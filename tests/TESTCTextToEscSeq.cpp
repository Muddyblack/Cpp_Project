#define BOOST_TEST_MODULE CTextToEscSeqtests
#include <boost/test/unit_test.hpp>
#include <Parameter.h>
#define private public
#include <CTextToEscSeq.h>
BOOST_AUTO_TEST_SUITE(CTextToEscSeqTestSuite)

BOOST_AUTO_TEST_CASE(convertTest)
{
    //Setup
    VariableStruct variableStruct;
    ParamStruct paramStruct;
    //Given Input
    std::string input = "Wortdavor\a\b\e\f\n\r\t\v\\\'\"\?Wortdahinter";

    //Expected Output
    const std::string expected = "Wortdavor\\a\\b\\e\\f\\n\\r\\t\\v\\\\\\\'\\\"\\?Wortdahinter";

    //Testing
    CTextToEscSeq converter(variableStruct,paramStruct);
    std::string result = converter.convert(input,60,"test.txt","\n");
    BOOST_CHECK(expected == result);

}

BOOST_AUTO_TEST_SUITE_END()