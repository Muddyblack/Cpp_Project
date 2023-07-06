cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)

set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_EXE_LINKER_FLAGS "--coverage")


set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

add_executable(GenTxtSrcCode ./lib/main.cpp ./lib/CTextToCPP.cpp ./lib/ProjectPathFinder.cpp)

ENABLE_TESTING()
# Set CTest properties for code coverage generation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -g -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -g -O0")

add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
target_link_libraries(TESTProjectPath
    boost_unit_test_framework-mgw13-mt-x64-1_82
    boost_filesystem-mgw13-mt-x64-1_82
)
add_test(NAME TESTProjectPath COMMAND TESTProjectPath)