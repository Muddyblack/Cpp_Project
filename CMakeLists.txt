cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)

# Set CPP Standard
set(CMAKE_CXX_STANDARD 17)

#setup Testing
set(CMAKE_CXX_FLAGS "--coverage -g -O0")
set(CMAKE_EXE_LINKER_FLAGS "--coverage -g -O0")
ENABLE_TESTING()

# Set the character encoding to UTF-8
set(CMAKE_CXX_FLAGS "-D_FILE_OFFSET_BITS=64 -D__STDC_FORMAT_MACROS -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

# includes
include_directories("./include" "./src")
# Include Boost headers
include_directories(${Boost_INCLUDE_DIRS})

# Program Executables
set(SOURCES
    "./src/GenTxtSrcCode.cpp" 
    "./lib/ProjectPathFinder.cpp"
    "./lib/Logger.cpp" 
    "./lib/CTextToCPP.cpp"
    "./lib/Extractor.cpp"
    "./lib/Parameter.cpp"
    "./lib/Helperfunctions.cpp"
    "./lib/ConsoleColors.cpp"
)
add_executable(GenTxtSrcCode ${SOURCES})

# Find Boost libraries
find_package(Boost REQUIRED COMPONENTS log log_setup thread system filesystem unit_test_framework)

# Link Boost libraries
target_link_libraries(GenTxtSrcCode 
    ${Boost_LIBRARIES} 
    Boost::log 
    Boost::log_setup 
    Boost::thread
    Boost::system
    Boost::filesystem
)

add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
target_link_libraries(TESTProjectPath
    ${Boost_LIBRARIES}
    Boost::unit_test_framework
    Boost::filesystem
)
add_test(NAME TESTProjectPath COMMAND TESTProjectPath)

