project(u3_01a)

add_executable(u3_01a main.c)

install(TARGETS u3_01a RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u3_01a ${CMAKE_THREAD_LIBS_INIT})
