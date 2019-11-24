cmake_minimum_required(VERSION 3.5)

project(OpenCVAssignments)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -march=native -std=c++17")

function(add_code name)
    find_package(OpenCV REQUIRED)
    add_executable(${name} ${CMAKE_CURRENT_SOURCE_DIR}/src/${name}.cpp)
    target_compile_definitions(${name} PRIVATE WITH_OPENCV WITH_NUMPY)
    target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include /usr/include/python3.8/ /usr/lib/python3.8/site-packages/numpy/core/include/)
    target_link_libraries(${name} ${OpenCV_LIBS} python3.8)
endfunction()

#add_code(test1)
#add_code(test2)
#add_code(test3)
#add_code(test4)
#add_code(test5)
add_code(test6)
