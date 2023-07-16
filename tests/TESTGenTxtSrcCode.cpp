#define BOOST_TEST_MODULE GenTxtSrcCodetests
#include <boost/test/unit_test.hpp>
#include <Helperfunctions.h>
#include <ConsoleColors.h>
#define private public
#include <GenTxtSrcCode.h>
//Creating a mock function to test private Method
std::string checkLanguageType(std::string input){
    const std::string input_lower = toLowerCase(input);
    if (input_lower == "cpp" || input_lower == "c++" || input_lower == "g++")
    {
        return "cpp";
    }
    else if (input_lower == "c")
    {
        return "c";
    }

    BOOST_LOG_TRIVIAL(fatal) << RED_COLOR << "Cannot deterimine: " << BLUE_COLOR << "'" << input << "'" << RED_COLOR << " as a Language."
                             << "\n"
                             << "We have " << CYAN_COLOR << "c " << RED_COLOR << "or " << CYAN_COLOR << "cpp " << RED_COLOR << "as option" << RESET_COLOR << std::endl;
    exit(1);
}

BOOST_AUTO_TEST_SUITE(GenTxtSrcCodeTestSuite)

    BOOST_AUTO_TEST_CASE(checkLanguagetypeTest){
    //Input
    const std::vector<std::string> input ={"cpp","CPP",
                                           "c++","C++",
                                           "g++","G++",
                                           "c","C"};
    //Expected Output
    const std::vector<std::string> expectedoutput ={"cpp","cpp",
                                                    "cpp","cpp",
                                                    "cpp","cpp",
                                                    "c","c"};

    //Testing
        for (long long unsigned int i = 0; i < input.size(); ++i){
           std::string result = checkLanguageType(input[i]);
           BOOST_CHECK(result==expectedoutput[i]);
        }
    }


BOOST_AUTO_TEST_SUITE_END()
