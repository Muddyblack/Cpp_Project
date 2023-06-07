cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)

# Set CPP Standard
set(CMAKE_CXX_STANDARD 17)

# Set the character encoding to UTF-8
set(CMAKE_CXX_FLAGS "-D_FILE_OFFSET_BITS=64 -D__STDC_FORMAT_MACROS -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

# includes
include_directories("./include")

# Program Executables
add_executable(GenTxtSrcCode "./lib/main.cpp" "./lib/ProjectPathFinder.cpp" "./lib/Logger.cpp")
# Link against Boost.Log
find_package(Boost REQUIRED COMPONENTS log log_setup thread)
# Find Boost.Log
find_package(Boost REQUIRED COMPONENTS log log_setup thread)
target_link_libraries(GenTxtSrcCode PRIVATE  Boost::log Boost::log_setup Boost::thread)

# Program Executables
#add_executable(GenTxtSrcCode ./lib/main.cpp  ./lib/ProjectPathFinder.cpp) #./lib/CTextToCPP.cpp
#add_executable(CTextToCPP ./lib/CTextToCPP.cpp ./lib/Extractor.cpp)

# Test Executables
#add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
#target_link_libraries(TESTProjectPath
#        Boost::unit_test_framework
#        Boost::filesystem
#)
