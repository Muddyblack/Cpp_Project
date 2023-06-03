cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)
add_executable(GenTxtSrcCode ./lib/main.cpp ./lib/CTextToCPP.cpp)