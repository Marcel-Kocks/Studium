project(u2_16)

add_executable(u2_16 main.c)

install(TARGETS u2_16 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries(u2_16 ${CMAKE_THREAD_LIBS_INIT})
