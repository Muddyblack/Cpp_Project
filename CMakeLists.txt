cmake_minimum_required(VERSION 3.10)
project(GENTXTSRCCODE)
# Set CPP Standard
set(CMAKE_CXX_STANDARD 17)

# Set the character encoding to UTF-8
set(CMAKE_CXX_FLAGS "-D_FILE_OFFSET_BITS=64 -D__STDC_FORMAT_MACROS -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")

# includes
include_directories(./include)

# Function to embed the custom icon into the executable
function(embed_icon EXECUTABLE ICON_FILE)
    if (WIN32)
        if (MSVC)
            set_target_properties(${EXECUTABLE} PROPERTIES LINK_FLAGS "/subsystem:windows /ENTRY:mainCRTStartup")
        endif()
        target_sources(${EXECUTABLE} PRIVATE ${ICON_FILE})
    endif()
endfunction()

# Program Executables
add_executable(GenTxtSrcCode ./lib/main.cpp ./lib/ProjectPathFinder.cpp)

# Embed the custom icon into the executable
embed_icon(GenTxtSrcCode ${CMAKE_CURRENT_SOURCE_DIR}/iconb.ico)

# Program Executables
#add_executable(GenTxtSrcCode ./lib/main.cpp  ./lib/ProjectPathFinder.cpp) #./lib/CTextToCPP.cpp
#add_executable(CTextToCPP ./lib/CTextToCPP.cpp ./lib/Extractor.cpp)

# Test Executables
#add_executable(TESTProjectPath ./tests/TESTProjectPathFinder.cpp ./lib/ProjectPathFinder.cpp)
#target_link_libraries(TESTProjectPath
#    boost_unit_test_framework-mgw13-mt-x64-1_82
#    boost_filesystem-mgw13-mt-x64-1_82
#)
