#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void generateCode(const std::string &inputFileName, const std::string &outputDir)
{
    // Codegenerierung für die angegebene Datei hier implementieren
    // Zum Beispiel: Datei öffnen, den Inhalt lesen und als Header- und Source-Datei speichern
    // Speicherung im angegebenen Ausgabeverzeichnis
}

int main(int argc, char *argv[])
{
    std::string inputFileName;
    std::string outputDir;

    po::options_description desc("Options");
    desc.add_options()("input-file", po::value<std::string>(&inputFileName)->required(), "Input file")("output-dir", po::value<std::string>(&outputDir)->required(), "Output directory");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("input-file") && vm.count("output-dir"))
    {
        try
        {
            po::notify(vm);
            generateCode(inputFileName, outputDir);
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
