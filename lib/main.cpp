#include "CTextToCPP.h"
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

// Color escape sequences
const std::string RESET_COLOR = "\033[0m";
const std::string GREEN_COLOR = "\033[32m";
const std::string RED_COLOR = "\033[31m";

int main(int argc, char *argv[])
{
    std::string inputFileName;
    std::string outputDir;

    po::options_description desc("Options");
    desc.add_options()("output-dir,o", po::value<std::string>(&outputDir)->required(), "Output directory")("help,h", "Print help message");

    po::positional_options_description positionalOptions;
    positionalOptions.add("input-file", 1);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(positionalOptions).run(), vm);

    if (vm.count("help"))
    {
        std::cout << "Usage: program_name [options] input-file\n";
        std::cout << desc << std::endl;
        std::cout << "Authors: Anna-Sophie Schneider, Julia Egger, Jonas Lehmann, Christian Kerhault, Jamie Fisher\n";
        std::cout << "Contact: kerhault.chris-it22.@it.dhbw-ravensburg.de\n";
        return 0;
    }
    if (vm.count("input-file") && vm.count("output-dir"))
    {
        try
        {
            inputFileName = vm["input-file"].as<std::string>();

            CTextToCPP codeGenerator;
            codeGenerator.generateCode(inputFileName, outputDir);

            std::cout << GREEN_COLOR << "Code generation successful!" << RESET_COLOR << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED_COLOR << "Code generation failed: " << e.what() << RESET_COLOR << std::endl;
        }
    }
    else
    {
        std::cout << "Usage: program_name [options] input-file\n";
        std::cout << desc << std::endl;
    }

    return 0;
}
