project(u2_14)

add_executable(u2_14 main.c)

install(TARGETS u2_14 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_14 ${CMAKE_THREAD_LIBS_INIT})
