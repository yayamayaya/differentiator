
file (GLOB MAIN_SRC ./*.cpp)
file (GLOB MAIN_HDR ./include/*.hpp)

add_executable(differentiator ${MAIN_SRC} ${MAIN_HDR})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(differentiator tokenizator tree_graphics parser optimizer)