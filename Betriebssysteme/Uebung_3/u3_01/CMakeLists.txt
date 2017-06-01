project(u3_01)

cmake_minimum_required(VERSION 3.5)


add_executable(u3_01 main.c)

install(TARGETS u3_01 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries( u3_01 ${CMAKE_THREAD_LIBS_INIT})
