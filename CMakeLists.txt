# CMakeList.txt : CMake project for tasks_week3_bezalel_jacober, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.15)

project ("tasks_week3_bezalel_jacober")
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()
add_executable (week03_zoo)
add_subdirectory (_include)
add_subdirectory (src)
include_directories(_include)

