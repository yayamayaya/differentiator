
project(tests)

file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_executable(tests ${HDR} ${SRC})

target_link_libraries(
    tests
    tokenizator 
    tree_graphics 
    parser 
    optimizer
    calculator
    diff_module
    output
)

target_include_directories(
    tests
    PRIVATE
    ./include/
)
