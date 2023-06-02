//g++ -o enum -I...Verzeichnis zu magic_enum... main.cpp --std=c++17
#include <magic_enum.hpp>

#include <iostream>
#include <string>
using namespace std;

enum class EEnableDisable {
    DISABLED,
    ENABLED
};

int main() {
    const string input = {"ENABLED"};

    //Text wird in Enum Wert gewandelt
    auto e = magic_enum::enum_cast<EEnableDisable>(input);

    if (e.has_value())
        //Hier findet die Rueckwandlung in Text statt
        cout << magic_enum::enum_name(e.value()) << endl;

    return 0;
}

