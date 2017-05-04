project(u2_07)

add_executable(u2_07 main.c)

install(TARGETS u2_07 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_07 ${CMAKE_THREAD_LIBS_INIT})
