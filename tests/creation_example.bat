del TEST.exe

cd /d "%~dp0"
g++ main.cpp ../lib/ProjectPathFinder.cpp -o mainy -I"../include"

timeout 10 > NUL
exit