
file (GLOB MAIN_SRC ./*.cpp)
file (GLOB MAIN_HDR ./include/*.hpp)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(differ ${MAIN_SRC} ${MAIN_HDR})

target_link_libraries(
    differ
    tokenizator 
    tree_graphics 
    parser 
    optimizer
    calculator
    diff_module
    output
    )