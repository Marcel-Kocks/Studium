project(u3_07)

add_executable(u3_07 main.c)

install(TARGETS u3_07 RUNTIME DESTINATION bin)

find_package(Threads REQUIRED)
target_link_libraries( u3_07 ${CMAKE_THREAD_LIBS_INIT})
