#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Funktion zum Speichern des generierten Codes in einer Datei
void saveToFile(const std::string &filename, const std::string &content)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        file << content;
        file.close();
        std::cout << "Datei " << filename << " erfolgreich erstellt." << std::endl;
    }
    else
    {
        std::cerr << "Fehler beim Erstellen der Datei " << filename << std::endl;
    }
}

int main(int argc, char *argv[])
{
    // Überprüfen, ob genügend Argumente übergeben wurden
    if (argc < 2)
    {
        std::cerr << "Zu wenige Argumente." << std::endl;
        std::cerr << "Verwendung: codegenerator <Inputdatei(en)> [<Optionen>]" << std::endl;
        return 1;
    }

    // Speicherort und Format der Ausgabedateien
    std::string outputDir = "./"; // Standardmäßig im aktuellen Verzeichnis
    std::string format = ".cpp";  // Standardmäßig C++-Dateien

    // Durchlaufen der Argumente und Extrahieren der Optionen
    for (int i = 2; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "-o" && i + 1 < argc)
        {
            outputDir = argv[i + 1];
            i++;
        }
        else if (arg == "-f" && i + 1 < argc)
        {
            format = argv[i + 1];
            i++;
        }
    }

    // Durchlaufen der Eingabedateien
    for (int i = 1; i < argc; i++)
    {
        std::string inputFile = argv[i];

        // Öffnen der Eingabedatei
        std::ifstream file(inputFile);
        if (!file.is_open())
        {
            std::cerr << "Fehler beim Öffnen der Datei " << inputFile << std::endl;
            continue;
        }

        // Lesen des Inhalts der Eingabedatei
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        // Generierung des Dateinamens für die Ausgabedateien
        std::string baseName = inputFile.substr(inputFile.find_last_of("/\\") + 1);
        std::string headerFile = outputDir + baseName + ".h";
        std::string sourceFile = outputDir + baseName + format;

        // Speichern des Inhalts in den Ausgabedateien
        saveToFile(headerFile, content);
        saveToFile(sourceFile, content);
    }

    return 0;
}
