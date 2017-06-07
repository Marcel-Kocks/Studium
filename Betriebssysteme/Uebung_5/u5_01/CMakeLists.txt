project(u5_01)

add_executable(u5_01 main.c)

install(TARGETS u5_01 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries( u5_01 ${CMAKE_THREAD_LIBS_INIT})
