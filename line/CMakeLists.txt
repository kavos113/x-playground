cmake_minimum_required(VERSION 3.28)
project(x-line)

add_executable(x-line main.c)

if (MSVC)
    target_include_directories(x-line PRIVATE $ENV{X_INCLUDE_DIR})
else ()
    target_include_directories(x-line PRIVATE /usr/include)
    target_link_libraries(x-line PRIVATE /usr/lib/x86_64-linux-gnu/libX11.so)
endif ()
