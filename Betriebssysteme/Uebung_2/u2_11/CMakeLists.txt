project(u2_11)

add_executable(u2_11 main.c)

install(TARGETS u2_11 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_11 ${CMAKE_THREAD_LIBS_INIT})
