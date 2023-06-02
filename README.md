# Cpp_Project

## Documentation

- [Google Documentation](https://docs.google.com/document/d/1sIRst9a-qz17fm-7Cz3ROre7z4TpLoECRdAn5lM3p3E/edit)

## Startup

To start working on this project so everybody has a similar version follow this Guide:

### Windows

1. Download the 64-Bit Mingw from [here](https://winlibs.com/)
2. Extract the `mingw` to the place you want it to be
3. Add `Path_to_mingw/mingw/bin` to your environment variables
4. Download and extract [Boost](https://www.boost.org/users/download/)
5. `cd path_to_your_boost_folder`
6. `bootstrap.bat mingw`
7. `./b2 toolset=gcc` (this will take a looong time)
8. (Optional) Copy the `boost` folder to `mingw/include` and the `stage/lib` folder to `mingw`
9. Create a `.vscode` folder in the Project. You can use the stuff from the `.vscode example`
10. Modify it to your needs. You can use now `ctrl+shift+B` for fast compiling

### Linux

---Coming Soon---
