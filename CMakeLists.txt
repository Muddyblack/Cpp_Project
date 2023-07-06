cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)

# Set CPP Standard
set(CMAKE_CXX_STANDARD 17)

#setup Testing
set(CMAKE_CXX_FLAGS "--coverage")
set(CMAKE_EXE_LINKER_FLAGS "--coverage")
ENABLE_TESTING()

# Set the character encoding to UTF-8
set(CMAKE_CXX_FLAGS "-D_FILE_OFFSET_BITS=64 -D__STDC_FORMAT_MACROS -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

# includes
include_directories("./include")
# Include Boost headers
include_directories(${Boost_INCLUDE_DIRS})

# Program Executables
add_executable(GenTxtSrcCode "./lib/main.cpp" "./lib/ProjectPathFinder.cpp" "./lib/Logger.cpp")
#add_executable(CTextToCPP ./lib/CTextToCPP.cpp ./lib/Extractor.cpp)

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
#target_link_libraries(CTextToCPP ${Boost_LIBRARIES})

add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
target_link_libraries(TESTProjectPath
    ${Boost_LIBRARIES}
    Boost::unit_test_framework
    Boost::filesystem
)
add_test(NAME TESTProjectPath COMMAND TESTProjectPath)


# Program Executables
#add_executable(GenTxtSrcCode ./lib/main.cpp  ./lib/ProjectPathFinder.cpp) #./lib/CTextToCPP.cpp
#add_executable(CTextToCPP ./lib/CTextToCPP.cpp ./lib/Extractor.cpp)

# Test Executables
#add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
#target_link_libraries(TESTProjectPath
#        Boost::unit_test_framework
#        Boost::filesystem
#)
