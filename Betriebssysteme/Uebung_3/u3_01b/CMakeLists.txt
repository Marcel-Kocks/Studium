project(u3_01b)

add_executable(u3_01b main.c)

install(TARGETS u3_01b RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries( u3_01b ${CMAKE_THREAD_LIBS_INIT})
