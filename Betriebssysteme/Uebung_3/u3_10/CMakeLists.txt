project(u3_10)

add_executable(u3_10 main.c)

install(TARGETS u3_10 RUNTIME DESTINATION bin)

cmake_minimum_required(VERSION 3.5)

find_package(Threads REQUIRED)
target_link_libraries( u3_10 ${CMAKE_THREAD_LIBS_INIT})
