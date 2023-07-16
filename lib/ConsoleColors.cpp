#ifdef _WIN32
#include <windows.h>

void EnableConsoleColors()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hConsole, &dwMode);
    SetConsoleMode(hConsole, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#else
// is required to work properly
void EnableConsoleColors()
{
}
#endif