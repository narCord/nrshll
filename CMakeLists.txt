cmake_minimum_required(VERSION 4.2)

project(nrshll C)

add_executable(nrshll
    main.c
    parser.c
    exec.c
)

target_include_directories(nrshll PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
