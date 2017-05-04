cmake_minimum_required(VERSION 3.5)

project(ahaus)

link_libraries(m)

add_executable(ahaus main.c primz_math.c)

#install(TARGETS ahaus RUNTIME DESTINATION bin)
