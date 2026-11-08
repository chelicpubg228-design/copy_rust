# copy_rust

Консольная игра для Windows.

🌐 **Сайт проекта:** https://chelicpubg228-design.github.io/copy_rust/

## Скачать

| Файл | Описание |
|------|----------|
| [`v5.5.exe`](versions/v5.5.exe) | Стабильная версия 5.5 |
| [`v_5_5_BETA.exe`](versions/v_5_5_BETA.exe) | Бета-сборка 5.5 |

Все версии игры лежат в папке [`versions`](versions/). Здесь указаны две последние, остальные смотри в папке.

## Быстрый старт

1. Скачай `v5.5.exe`.
2. Положи рядом файл `config_cop_rast.json`.
3. Запусти `v5.5.exe` двойным кликом или из командной строки.

> Если Windows SmartScreen выдаёт предупреждение, нажми «Подробнее» → «Выполнить в любом случае».

## Настройки

Параметры игры находятся в файле `config_cop_rast.json`. Открой его любым текстовым редактором, измени значения и перезапусти игру.

<!-- TODO: опиши ключи конфига, например: "ключ" — что делает -->

## Сборка из исходников

Нужны [CMake](https://cmake.org/) и компилятор C++ (MSVC или MinGW).

```bash
git clone https://github.com/chelicpubg228-design/copy_rust.git
cd copy_rust
cmake -S . -B build
cmake --build build
```

## Структура проекта

```
copy_rust/
├── src/                    исходный код игры
├── build/                  результаты сборки
├── builds_py/              вспомогательные Python-скрипты сборки
├── CMakeLists.txt          конфигурация сборки
├── config_cop_rast.json    настройки игры
└── versions/               готовые версии (v5.5.exe, v_5_5_BETA.exe)
```

## Об игре

Консольная игра: после запуска вводишь имя и попадаешь в главное меню, где пункты выбираются по номеру.

```
v 5.5
enter name user~# user
=============menu===========
1 info        2 exit
3 sleep       4 help
5 craft       6 don armor
7 undon armor 8 statistic user
9 statistic axe 10 free mode
11 to setting 12 to console
13 to stastic resours 14 to status table
15 to menu mini plays 16 to out menu
=============menu===========
x = 0
y = 0

user~$
```

<!-- TODO: опиши цель игры и что делают пункты меню (craft, free mode, mini plays и т. д.) -->

## Лицензия

<!-- TODO: добавь файл LICENSE (например, MIT) и укажи его здесь -->
