cmake_minimum_required(VERSION 3.12)
project(real_copy_rust)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories($ENV{INCLUDE_VCPKG_for_me})
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/system_rust/copy_rust.cpp
    src/resours_rust/crafts.cpp
    src/sample_rust/fight.cpp
    src/sample_rust/for_details.cpp
    src/sample_rust/for_mine_resours.cpp
    src/sample_rust/for_mini_function.cpp
    src/resours_rust/resourss.cpp
    src/system_rust/ssitem_fun.cpp
    src/user_rust/work_json.cpp
    src/user_rust/menu.cpp
    src/coordinates_rust/Coordinates_rust.cpp
    src/coordinates_rust/free_mode_rust.cpp
    src/resours_rust/tools_rust.cpp
    src/coordinates_rust/loc_coordin.cpp
    src/system_rust/for_help.cpp
    src/user_rust/setting_us.cpp 
    src/system_rust/exit_rust.cpp
    src/console_copy_rust/main_console_rust.cpp
    src/console_copy_rust/for_print_help_console.cpp
    src/console_copy_rust/tp_console_copy_rust.cpp
    src/console_copy_rust/for_user_change.cpp
    src/algorithms_rust/max_min_rust.cpp
)

if(MSVC)
    add_compile_options(/permissive- /EHsc)
endif()

add_executable(real_copy_rust ${SOURCES})
