
file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

include_directories(
    ./include/
)

add_library(tree_graphics ${HDR} ${SRC})