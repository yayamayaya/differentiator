
file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_library(parser ${HDR} ${SRC})