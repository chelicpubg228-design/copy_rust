cmake_minimum_required(VERSION 3.12)
project(real_copy_rust)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories($ENV{INCLUDE_VCPKG_for_me})
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    app/system_rust/copy_rust.cpp
    app/resours_rust/crafts.cpp
    app/sample_rust/fight.cpp
    app/sample_rust/for_details.cpp
    app/sample_rust/for_mine_resours.cpp
    app/sample_rust/for_mini_function.cpp
    app/resours_rust/resourss.cpp
    app/system_rust/ssitem_fun.cpp
    app/user_rust/work_json.cpp
    app/user_rust/menu.cpp
    app/coordinates_rust/Coordinates_rust.cpp
    app/coordinates_rust/free_mode_rust.cpp
    app/resours_rust/tools_rust.cpp
    app/coordinates_rust/loc_coordin.cpp
    app/system_rust/for_help.cpp
    app/user_rust/setting_us.cpp 
    app/system_rust/exit_rust.cpp
    app/console_copy_rust/main_console_rust.cpp
    app/console_copy_rust/for_print_help_console.cpp
    app/console_copy_rust/tp_console_copy_rust.cpp
    app/console_copy_rust/for_user_change.cpp
)

if(MSVC)
    add_compile_options(/permissive- /EHsc)
endif()

add_executable(real_copy_rust ${SOURCES})
