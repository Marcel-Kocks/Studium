project(u3_09)

add_executable(u3_09 main.c)

cmake_minimum_required(VERSION 3.5)


install(TARGETS u3_09 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries( u3_09 ${CMAKE_THREAD_LIBS_INIT})
