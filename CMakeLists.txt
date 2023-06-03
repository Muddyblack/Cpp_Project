cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)

set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_EXE_LINKER_FLAGS "--coverage")


set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

add_executable(GenTxtSrcCode ./lib/main.cpp ./lib/CTextToCPP.cpp ./lib/ProjectPathFinder.cpp)



add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
target_link_libraries(TESTProjectPath
    boost_unit_test_framework-mgw13-mt-x64-1_82
    boost_filesystem-mgw13-mt-x64-1_82
)
add_test(NAME TESTProjectPath COMMAND TESTProjectPath)