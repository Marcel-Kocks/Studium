project(u2_10)

add_executable(u2_10 main.c)

install(TARGETS u2_10 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_10 ${CMAKE_THREAD_LIBS_INIT})
