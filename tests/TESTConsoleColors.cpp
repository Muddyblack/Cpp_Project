#define BOOST_TEST_MODULE ConsoleColorstests
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/output_test_stream.hpp>
#include <ConsoleColors.h>
BOOST_AUTO_TEST_SUITE(ConsoleColorTestSuite)

    BOOST_AUTO_TEST_CASE(baiscfuntionality){
        const std::string expectedoutput ="This will be "
                                    "\033[32mgreen"
                                    " \033[31mred"
                                    " \033[38;5;208morange"
                                    " \033[36mcyan"
                                    " \033[30mblack"
                                    " \033[38;5;19mblue"
                                    " \033[1;32mstronggreen"
                                    " \033[0mand this normal";
        //Testing
        boost::test_tools::output_test_stream output;
        output << "This will be ";
        output << GREEN_COLOR << "green ";
        output << RED_COLOR << "red ";
        output << ORANGE_COLOR << "orange ";
        output << CYAN_COLOR << "cyan ";
        output << BLACK_COLOR << "black ";
        output << BLUE_COLOR << "blue ";
        output << STRONG_GREEN_COLOR << "stronggreen ";
        output << RESET_COLOR << "and this normal";

        BOOST_CHECK(output.is_equal(expectedoutput));

    }
BOOST_AUTO_TEST_SUITE_END()