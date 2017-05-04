project(u2_13)

add_executable(u2_13 main.c)

install(TARGETS u2_13 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_13 ${CMAKE_THREAD_LIBS_INIT})
