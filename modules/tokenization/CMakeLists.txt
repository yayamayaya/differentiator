
file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_library(tokenizator ${HDR} ${SRC})

target_include_directories(
    tokenizator
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)