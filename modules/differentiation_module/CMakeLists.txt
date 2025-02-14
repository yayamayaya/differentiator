
file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_library(diff_module ${HDR} ${SRC})