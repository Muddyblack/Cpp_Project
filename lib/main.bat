cd /d "%~dp0"

del main.exe
g++ -std=c++17 -o main main.cpp CTextToCPP.cpp -lboost_program_options-mgw13-mt-d-x64-1_82 -I "../include"

timeout /t 10 >nul

exit