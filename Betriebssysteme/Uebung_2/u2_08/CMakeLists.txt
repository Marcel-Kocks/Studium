project(u2_08)

add_executable(u2_08 main.c)

install(TARGETS u2_08 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_08 ${CMAKE_THREAD_LIBS_INIT})
