project(u3_08a)

add_executable(u3_08a main.c)

install(TARGETS u3_08a RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries( u3_08a ${CMAKE_THREAD_LIBS_INIT})
