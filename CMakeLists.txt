cmake_minimum_required(VERSION 3.15)

project(differentiator)

#set(CMAKE_CPP_COMPILER ${CPP_COMPILER})

add_definitions(-DGRAPH)

#add_compile_definitions(-DBIN_PATH=\"${CMAKE_CURRENT_BINARY_DIR}\")

add_definitions(
    -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat
-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op
-Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow
-Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers
-Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector
-fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla
)

file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp)
file(GLOB HDRS ${CMAKE_CURRENT_SOURCE_DIR}/include/*hpp)

include_directories(
    GLOBAL
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(differentiator ${SRCS} ${HDRS})

#add_subdirectory(server ${CMAKE_CURRENT_BINARY_DIR}/server_interface)
#add_subdirectory(task_2 ${CMAKE_CURRENT_BINARY_DIR}/task_2)

