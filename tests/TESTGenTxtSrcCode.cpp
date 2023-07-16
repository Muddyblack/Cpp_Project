#define BOOST_TEST_MODULE GenTxtSrcCodetests
#include <boost/test/unit_test.hpp>
#define private public
#include <GenTxtSrcCode.h>
BOOST_AUTO_TEST_SUITE(GenTxtSrcCodeTestSuite)

    BOOST_AUTO_TEST_CASE(checkLanguagetypeTest){
    char *argv[1] = {nullptr};
    GenTxtSrcCode genTxtSrcCode(1,argv);
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

    //genTxtSrcCode().checkLanguageType(input[0]);
    //Testing
        for (long long unsigned int i = 0; i < input.size(); ++i){
           //BOOST_CHECK(genTxtSrcCode().checkLanguageType(input[i])==expectedoutput[i]);
        }

    }
    BOOST_AUTO_TEST_CASE(isValisFileNameTest){


    }
    BOOST_AUTO_TEST_CASE(isValidNamespaceTest){


    }
    BOOST_AUTO_TEST_CASE(isValidVariableNameTest){


    }

BOOST_AUTO_TEST_SUITE_END()
