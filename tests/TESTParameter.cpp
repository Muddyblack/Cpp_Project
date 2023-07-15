#define BOOST_TEST_MODULE Parametertests
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>
#include "Parameter.h"
#include <ConsoleColors.h>

BOOST_AUTO_TEST_SUITE(ParameterTestSuite)

    BOOST_AUTO_TEST_CASE(printParamStructTest)
    {
        //Input
        ParamStruct parameter;
        parameter.headerDir ="headerdirectory";
        parameter.sourceDir ="sourcedirectory";
        parameter.outputType ="cpp";
        parameter.outputFilename ="DerFileName";
        parameter.namespaceName ="SpaceName";
        parameter.signPerLine =60;
        parameter.sortByVarname =false;

        //Expected Output
        const std::string expectedoutput ="Program arguments:\nHeader Directory: \033[36mheaderdirectory\033[0m\nSource Directory: \033[36msourcedirectory\033[0m\n"
                                    "Output Type: \033[36mcpp\033[0m\nOutput Filename: \033[36mDerFileName\033[0m\nNamespace Name: \033[36mSpaceName\033[0m\n"
                                    "Sign Per Line: \033[36m60\033[0m\nSort By Variable Name: \033[36m0\033[0m\n\n";

        //Testing
        boost::test_tools::output_test_stream output;
        output << "Program arguments:\n";
        output << "Header Directory: " << CYAN_COLOR << parameter.headerDir << RESET_COLOR << std::endl;
        output << "Source Directory: " << CYAN_COLOR << parameter.sourceDir << RESET_COLOR << std::endl;
        output << "Output Type: " << CYAN_COLOR << parameter.outputType << RESET_COLOR << std::endl;
        output << "Output Filename: " << CYAN_COLOR << parameter.outputFilename << RESET_COLOR << std::endl;
        output << "Namespace Name: " << CYAN_COLOR << (parameter.namespaceName) << RESET_COLOR << std::endl;
        output << "Sign Per Line: " << CYAN_COLOR << parameter.signPerLine << RESET_COLOR << std::endl;
        output << "Sort By Variable Name: " << CYAN_COLOR << parameter.sortByVarname << RESET_COLOR << std::endl;
        output << std::endl;

        BOOST_CHECK(output.is_equal(expectedoutput));
    }
    BOOST_AUTO_TEST_CASE(printVariableStructTest){
        //Input
        VariableStruct variableStruct;
        variableStruct.name ="Variablenname";
        variableStruct.seq ="HEX";
        variableStruct.nl ="CR";
        variableStruct.addtextpos =true;
        variableStruct.addtextsegment =false;
        variableStruct.doxygen ="";

        //Expected Output
        const std::string expectedoutput ="Program variable: \033[38;5;19mVariablenname\033[0m\n"
                                    "Add the text position: \033[36m1\033[0m\n"
                                    "Add the text segment: \033[36m0\033[0m\n"
                                    "The Doxygentext: \033[36m\033[0m\n"
                                    "The New Line Seperator: \033[36mCR\033[0m\n"
                                    "The Encoding Type: \033[36mHEX\033[0m\n\n";

        //Testing
        boost::test_tools::output_test_stream output;
        output << "Program variable: "<< BLUE_COLOR << variableStruct.name << RESET_COLOR << "\n";
        output << "Add the text position: " << CYAN_COLOR << variableStruct.addtextpos << RESET_COLOR << std::endl;
        output << "Add the text segment: " << CYAN_COLOR << variableStruct.addtextsegment << RESET_COLOR << std::endl;
        output << "The Doxygentext: " << CYAN_COLOR << variableStruct.doxygen << RESET_COLOR << std::endl;
        output << "The New Line Seperator: " << CYAN_COLOR << variableStruct.nl << RESET_COLOR << std::endl;
        output << "The Encoding Type: " << CYAN_COLOR << variableStruct.seq << RESET_COLOR << std::endl;
        output << std::endl;

        BOOST_CHECK(output.is_equal(expectedoutput));
    }

BOOST_AUTO_TEST_SUITE_END()
