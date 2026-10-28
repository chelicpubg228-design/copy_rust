# это официальный сборщий copy_console_rust
# ссылка на сайт: сайта нету 
# удачной сборки!
# только перед началом сделайте папки D:/rust_ccop/, D:/rust_ccop/copy_rust/ и D:/rust_ccop/copy_rust/real_copy_rust 
import os
import queue
import shutil
import subprocess
import threading

import customtkinter as ctk

PROJECT_DIR = "D:/rust_ccop/copy_rust/real_copy_rust"
BUILD_DIR = PROJECT_DIR + "/build"

ENCODING = "utf-8"

ctk.set_appearance_mode("dark")
ctk.set_default_color_theme("blue")


class BuildMaster(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.title("Мастер сборки")
        self.geometry("820x600")
        self.minsize(600, 400)

        self.log_queue = queue.Queue()
        self.process = None
        self.running = False

        self.clean_var = ctk.BooleanVar(value=False)
        self.status_var = ctk.StringVar(value="Готов к работе")

        self.build_ui()
        self.poll_queue()

    # ---------- интерфейс ----------
    def build_ui(self):
        title = ctk.CTkLabel(self, text="Выберите конфигурацию сборки",
                             font=ctk.CTkFont(size=20, weight="bold"))
        title.pack(pady=(15, 5))

        path_label = ctk.CTkLabel(self, text=BUILD_DIR, text_color="gray")
        path_label.pack()

        buttons = ctk.CTkFrame(self, fg_color="transparent")
        buttons.pack(pady=15)

        self.btn_debug = ctk.CTkButton(buttons, text="Debug", width=140, height=40,
                                       command=self.start_debug)
        self.btn_debug.grid(row=0, column=0, padx=8)

        self.btn_release = ctk.CTkButton(buttons, text="Release", width=140, height=40,
                                         command=self.start_release)
        self.btn_release.grid(row=0, column=1, padx=8)

        self.btn_stop = ctk.CTkButton(buttons, text="Стоп", width=100, height=40,
                                      fg_color="#b33a3a", hover_color="#8f2e2e",
                                      state="disabled", command=self.stop)
        self.btn_stop.grid(row=0, column=2, padx=8)

        options = ctk.CTkFrame(self, fg_color="transparent")
        options.pack()

        clean_box = ctk.CTkCheckBox(options, text="Чистая сборка (удалить папку build)",
                                    variable=self.clean_var)
        clean_box.pack(side="left", padx=10)

        clear_btn = ctk.CTkButton(options, text="Очистить лог", width=110,
                                  fg_color="gray30", hover_color="gray40",
                                  command=self.clear_log)
        clear_btn.pack(side="left", padx=10)

        self.progress = ctk.CTkProgressBar(self, mode="indeterminate")
        self.progress.pack(fill="x", padx=20, pady=15)
        self.progress.set(0)

        self.log = ctk.CTkTextbox(self, font=("Consolas", 12), wrap="none")
        self.log.pack(fill="both", expand=True, padx=20)
        self.log.configure(state="disabled")

        self.log.tag_config("error", foreground="#f48771")
        self.log.tag_config("warning", foreground="#e5c07b")
        self.log.tag_config("step", foreground="#61afef")
        self.log.tag_config("ok", foreground="#98c379")

        self.status = ctk.CTkLabel(self, textvariable=self.status_var, anchor="w")
        self.status.pack(fill="x", padx=20, pady=10)

    # ---------- кнопки ----------
    def start_debug(self):
        self.start("Debug")

    def start_release(self):
        self.start("Release")

    def clear_log(self):
        self.log.configure(state="normal")
        self.log.delete("1.0", "end")
        self.log.configure(state="disabled")

    def stop(self):
        if self.process is None:
            return

        self.add_line("Остановка сборки...", "warning")
        if os.name == "nt":
            
            subprocess.run(["taskkill", "/T", "/F", "/PID", str(self.process.pid)],
                           capture_output=True)
        else:
            self.process.terminate()

    # ---------- запуск ----------
    def start(self, config):
        if self.running:
            return

        self.running = True
        self.set_buttons(False)
        self.progress.configure(mode="indeterminate")
        self.progress.start()
        self.status_var.set("Идёт сборка " + config + "...")

        worker = threading.Thread(target=self.worker, args=(config,), daemon=True)
        worker.start()

    def worker(self, config):
        if self.clean_var.get():
            self.log_queue.put(("step", "=== Очистка папки build ==="))
            shutil.rmtree(BUILD_DIR, ignore_errors=True)

        os.makedirs(BUILD_DIR, exist_ok=True)

        steps = [
            ("Конфигурация (cmake ..)",
             ["cmake", "..", "-A", "x64", "-T", "host=x64"]),
            ("Сборка " + config,
             ["cmake", "--build", ".", "--config", config, "--", "/m:1"]),
        ]

        for title, command in steps:
            self.log_queue.put(("step", "=== " + title + " ==="))

            if not self.run_step(command):
                self.log_queue.put(("done", False))
                return

        self.log_queue.put(("done", True))

    def run_step(self, command):
        flags = 0
        if os.name == "nt":
            flags = subprocess.CREATE_NO_WINDOW

        try:
            self.process = subprocess.Popen(
                command, cwd=BUILD_DIR,
                stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                text=True, encoding=ENCODING, errors="replace",
                creationflags=flags,
            )
        except FileNotFoundError:
            self.log_queue.put(("error", "cmake не найден. Он добавлен в PATH?"))
            return False

        for line in self.process.stdout:
            self.log_queue.put(("line", line.rstrip()))

        code = self.process.wait()
        self.process = None

        if code != 0:
            self.log_queue.put(("error", "Шаг завершился с кодом " + str(code)))
            return False

        return True

    # ---------- обновление интерфейса ----------
    def poll_queue(self):
        while True:
            try:
                kind, data = self.log_queue.get_nowait()
            except queue.Empty:
                break

            if kind == "done":
                self.finish(data)
            elif kind == "line":
                self.add_line(data, self.detect_tag(data))
            else:
                self.add_line(data, kind)

        self.after(100, self.poll_queue)

    def detect_tag(self, text):
        low = text.lower()
        if "error" in low or "ошибка" in low:
            return "error"
        if "warning" in low or "предупреждение" in low:
            return "warning"
        return None

    def add_line(self, text, tag=None):
        self.log.configure(state="normal")
        if tag:
            self.log.insert("end", text + "\n", tag)
        else:
            self.log.insert("end", text + "\n")
        self.log.see("end")
        self.log.configure(state="disabled")

    def set_buttons(self, enabled):
        state = "normal" if enabled else "disabled"
        self.btn_debug.configure(state=state)
        self.btn_release.configure(state=state)
        self.btn_stop.configure(state="disabled" if enabled else "normal")

    def finish(self, success):
        self.running = False
        self.progress.stop()
        self.progress.set(1 if success else 0)
        self.set_buttons(True)

        if success:
            self.status_var.set("Сборка прошла успешно")
            self.add_line("Готово! Сборка прошла успешно", "ok")
        else:
            self.status_var.set("Сборка завершилась с ошибкой или была остановлена")


if __name__ == "__main__":
    app = BuildMaster()
    app.mainloop()
