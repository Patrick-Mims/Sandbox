cmake_minimum_required(VERSION 3.20)

project(main VERSION 1.0)

include_directories("inc")

include_directories("${PROJECT_BINARY_DIR}")

file(GLOB SOURCES "src/*.cc")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_executable(${PROJECT_NAME} ${SOURCES})
