cmake_minimum_required(VERSION 3.16)
project(c-learning-projects C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED true)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wshadow -Wconversion -Wformat=2 -Wswitch-default -Wstrict-prototypes)
add_library(utilities STATIC ${CMAKE_SOURCE_DIR}/utilities/utils.c)
target_include_directories(utilities PUBLIC ${CMAKE_SOURCE_DIR}/utilities)
add_executable(math-operations ${CMAKE_SOURCE_DIR}/math-operations/math-operations.c)


target_link_libraries(math-operations utilities)
