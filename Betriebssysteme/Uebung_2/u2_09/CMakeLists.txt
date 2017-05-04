project(u2_09)

add_executable(u2_09 main.c)

install(TARGETS u2_09 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_09 ${CMAKE_THREAD_LIBS_INIT})
