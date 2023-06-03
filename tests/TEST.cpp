#define BOOST_TEST_MODULE MyTests
#include <boost/test/unit_test.hpp>

#include "CTextToCPP.h"

BOOST_AUTO_TEST_CASE(GenerateCodeTest)
{
    // Input test data
    std::string inputFileName = "input_file.txt";
    std::string outputDir = "output_dir/";

    // Create an instance of CTextToCPP
    CTextToCPP codeGenerator;

    // Call the generateCode function
    BOOST_CHECK_NO_THROW(codeGenerator.generateCode(inputFileName, outputDir));

    // Perform additional assertions if needed
    // ...

    // Verify the generated code or any other desired outcomes
    // ...
}
