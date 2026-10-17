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
    system_rust/for_help.cpp
    user_rust/setting_us.cpp
)

if(MSVC)
    add_compile_options(/permissive-)
endif()
add_executable(real_copy_rust ${SOURCES})
