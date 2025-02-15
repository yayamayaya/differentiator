
file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_library(calculator ${HDR} ${SRC})

target_link_libraries(calculator optimizer)