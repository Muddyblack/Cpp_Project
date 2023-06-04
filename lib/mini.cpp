#include <iostream>
#include <getopt.h>

int main(int argc, char *argv[])
{
    // Standard directories
    std::string outputDir = "PROJECT_PATH\\output\\"; /**< Output directory */

    // Options
    const struct option longOptions[3] = {
        {"output-dir", required_argument, nullptr, 'O'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}};
    const int options_amount = sizeof(longOptions) / sizeof(longOptions[0]);

    int opt;
    int option_index;
    while ((opt = getopt_long(argc, argv, "O:h", longOptions, &option_index)) != -1)
    {
        std::cout << "Long option index: " << option_index << std::endl;
        if (option_index > options_amount - 1)
        {
            std::cout << static_cast<char>(optopt) << std::endl;
        }
        else
        {
            std::cout << "Option name: " << longOptions[option_index].name << std::endl;
        }

        switch (opt)
        {
        case 'O':
            outputDir = optarg;
            break;
        case 'h':
            // printHelpText();
            exit(0);
        case '?':
            if ((optopt == 'O' || optopt == 'h'))
            {
                std::cout << "OK ... option '-" << static_cast<char>(optopt) << "' without argument"
                          << std::endl;
                exit(1);
            }
            else if (isprint(optopt))
            {
                std::cerr << "ERR ... Unknown option -" << static_cast<char>(optopt) << std::endl;
                exit(-1);
            }
            else
            {
                std::cerr << "ERR ... Unknown option character \\x" << static_cast<char>(optopt) << std::endl;
                exit(-1);
            }
        }
    }
    return 0;
}
