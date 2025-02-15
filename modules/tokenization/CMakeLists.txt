
file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_library(tokenizator ${HDR} ${SRC})

target_link_libraries(tokenizator differ)