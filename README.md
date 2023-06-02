<p align="center">
  <img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg" alt="cosmetic"/>
  <img src="https://forthebadge.com/images/badges/not-a-bug-a-feature.svg" alt="cosmetic"/>
  <img src="https://ForTheBadge.com/images/badges/uses-git.svg" alt="cosmetic"/>
  <img src="https://ForTheBadge.com/images/badges/built-with-love.svg" alt="cosmetic"/>
  <img src="https://forthebadge.com/images/badges/powered-by-coders-sweat.svg" alt="cosmetic"/>
</p>

<pre align="center">

 ______  ______  __   __  ______  __  __  ______  ______  ______  ______  ______  ______  _____   ______    
/\  ___\/\  ___\/\ "-.\ \/\__  _\/\_\_\_\/\__  _\/\  ___\/\  == \/\  ___\/\  ___\/\  __ \/\  __-./\  ___\   
\ \ \__ \ \  __\\ \ \-.  \/_/\ \/\/_/\_\/\/_/\ \/\ \___  \ \  __<\ \ \___\ \ \___\ \ \/\ \ \ \/\ \ \  __\   
 \ \_____\ \_____\ \_\\"\_\ \ \_\  /\_\/\_\ \ \_\ \/\_____\ \_\ \_\ \_____\ \_____\ \_____\ \____-\ \_____\ 
  \/_____/\/_____/\/_/ \/_/  \/_/  \/_/\/_/  \/_/  \/_____/\/_/ /_/\/_____/\/_____/\/_____/\/____/ \/_____/ 
                                                                                                            

                                                                                      version 0.0.1
</pre>

<a href="https://github.com/Muddyblack/GenTxtSrcCode/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Muddyblack/GenTxtSrcCode" />
</a>

## Table of Contents

- [Startup](#startup)
- [Libraries](#libraries)

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

## Libraries

- [Boost](https://www.boost.org/users/download/)
