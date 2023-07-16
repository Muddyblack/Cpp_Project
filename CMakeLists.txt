cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)

# Set CTest output color to Always
set(CTEST_OUTPUT_COLOR Always)

# Set CPP Standard
set(CMAKE_CXX_STANDARD 17)

#setup Testing
set(CMAKE_CXX_FLAGS "--coverage -g -O0")
set(CMAKE_EXE_LINKER_FLAGS "--coverage -g -O0")
set(CTEST_USE_LAUNCHERS OFF)
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
    "./lib/CTextToEscSeq.cpp"
    "./lib/CTextToHexSeq.cpp"
    "./lib/CTextToOctSeq.cpp"
    "./lib/CTextToRawHexSeq.cpp"
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
#Add Tests
add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
target_link_libraries(TESTProjectPath
    ${Boost_LIBRARIES}
    Boost::unit_test_framework
    Boost::filesystem
)
add_test(NAME TESTProjectPath COMMAND TESTProjectPath)

add_executable(TESTExtractor ./tests/TESTExtractor.cpp ./lib/Extractor.cpp)
target_link_libraries(TESTExtractor
        ${Boost_LIBRARIES}
        Boost::unit_test_framework
        )
add_test(NAME TESTExtractor COMMAND TESTExtractor)

add_executable(TestParameter ./tests/TESTParameter.cpp ./lib/Parameter.cpp)
target_link_libraries(TestParameter
        ${Boost_LIBRARIES}
        Boost::unit_test_framework
        )
add_test(NAME TestParameter COMMAND TestParameter)

add_executable(TestConsoleColors ./tests/TESTConsoleColors.cpp ./lib/ConsoleColors.cpp)
target_link_libraries(TestConsoleColors
        ${Boost_LIBRARIES}
        Boost::unit_test_framework
        )
add_test(NAME TESTConsoleColors COMMAND TESTConsoleColors)

add_executable(TESTGenTxtSrcCode ./tests/TESTGenTxtSrcCode.cpp ${SOURCES} ./src/GenTxtSrcCode.cpp)
target_link_libraries(TESTGenTxtSrcCode
        ${Boost_LIBRARIES}
        Boost::unit_test_framework
        Boost::log 
        Boost::log_setup 
        Boost::thread
        Boost::system
        Boost::filesystem
        )
add_test(NAME TESTGenTxtSrcCode COMMAND TESTGenTxtSrcCode)

add_executable(TESTCTextToEscSeq ./tests/TESTCTextToEscSeq.cpp ${SOURCES} ./lib/CTextToEscSeq.cpp)
target_link_libraries(TESTCTextToEscSeq
        ${Boost_LIBRARIES}
        Boost::unit_test_framework
        )
add_test(NAME TESTCTextToEscSeq COMMAND TESTCTextToEscSeq)

add_executable(TESTHelperfunctions ./tests/TESTHelperfunctions.cpp ./lib/Helperfunctions.cpp)
target_link_libraries(TESTHelperfunctions
        ${Boost_LIBRARIES}
        Boost::unit_test_framework
        )
add_test(NAME TESTHelperfunctions COMMAND TESTHelperfunctions)
