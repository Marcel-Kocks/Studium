project(u2_12)

add_executable(u2_12 main.c)

install(TARGETS u2_12 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_12 ${CMAKE_THREAD_LIBS_INIT})
