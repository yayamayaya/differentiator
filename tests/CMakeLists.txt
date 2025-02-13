
project(tests)

file (GLOB HDR ./include/*.hpp)
file (GLOB SRC ./*.cpp)

add_executable(tests ${HDR} ${SRC})

target_include_directories(
    tests
    PRIVATE
    ./include/
)
