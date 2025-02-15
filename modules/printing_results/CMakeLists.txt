
file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

include_directories(
    ./include/
)

add_library(output ${HDR} ${SRC})