import os 

print("компиляция идет...............................")
CMAKE_CONTENT = """
        
cmake_minimum_required(VERSION 3.12)
project(real_copy_rust)

set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SOURCES
    system_rust/copy_rust.cpp
    resours_rust/crafts.cpp
    sample_rust/fight.cpp
    sample_rust/for_details.cpp
    sample_rust/for_mine_resours.cpp
    sample_rust/for_mini_function.cpp
    resours_rust/resourss.cpp
    system_rust/ssitem_fun.cpp
    user_rust/work_json.cpp
    user_rust/menu.cpp
    coordinates_rust/Coordinates_rust.cpp
    coordinates_rust/free_mode_rust.cpp
    resours_rust/tools_rust.cpp
    coordinates_rust/loc_coordin.cpp
)

if(MSVC)
    add_compile_options(/permissive-)
endif()
add_executable(real_copy_rust ${SOURCES})
"""


PROJECT_DIR = r"D:/rust_ccop/copy_rust/real_copy_rust"
BUILD_DIR = os.path.join(PROJECT_DIR, "build")
CMAKE_FILE = os.path.join(PROJECT_DIR, "CMakeLists.txt")
print("загрузка файла................")

# 1. Создать CMakeLists.txt, если нет
if not os.path.exists(CMAKE_FILE):
    open(CMAKE_FILE, "w").write(CMAKE_CONTENT)
    print("CMakeLists.txt создан")



os.system("cd build && cmake .. && cmake --build . --config Debug")

print(f"файл скомпилирован в D:/rust_ccop/copy_rust/real_copy_rust/build/Debug/real_copy_rust.exe")
