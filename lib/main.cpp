#include "CodeGenerator.h"
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    std::string inputFileName;
    std::string outputDir;

    po::options_description desc("Options");
    desc.add_options()("input-file,i", po::value<std::string>(&inputFileName)->required(), "Input file")("output-dir,o", po::value<std::string>(&outputDir)->required(), "Output directory");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("input-file") && vm.count("output-dir"))
    {
        try
        {
            po::notify(vm);

            CodeGenerator codeGenerator;
            codeGenerator.generateCode(inputFileName, outputDir);

            std::cout << "Code generation successful!" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Code generation failed: " << e.what() << std::endl;
        }
    }
    else
    {
        std::cout << desc << std::endl;
    }

    return 0;
}