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

<p align="center">
  <img src="https://img.shields.io/badge/Maintained%3F-yes-green.svg?" alt="cosmetic"/>
  <img src="https://img.shields.io/badge/license-GPL-blue?" alt="cosmetic"/>
  <a href="https://github.com/Muddyblack/GenTxtSrcCode/releases" rel="noopener noreferrer"><img src="https://img.shields.io/github/v/release/Muddyblack/GenTxtSrcCode" ></a>
</p>

<a href="https://github.com/Muddyblack/GenTxtSrcCode/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=Muddyblack/GenTxtSrcCode" />
</a>

## Documentation

- [Google Documentation](https://docs.google.com/document/d/1sIRst9a-qz17fm-7Cz3ROre7z4TpLoECRdAn5lM3p3E/edit)

## Startup

To start working on this project so everybody has a similar version follow this Guide:

### Windows

- Download the 64-Bit Mingw from [here](https://winlibs.com/)
- Extract the `mingw` to the place you want it to be
- Add `Path_to_mingw/mingw/bin` to your environment variables
- Download and extract [Boost](https://www.boost.org/users/download/)
- `cd path_to_your_boost_folder`
- `bootstrap.bat mingw`
- `./b2 toolset=gcc` (this will take a looong time)
- (Optional) Copy the `boost` folder to `mingw/include` and the `stage/lib` folder to `mingw`
- Install VS-Code
- Add `C/C++ Extension Pack` Extension
- Add `Cmake Tools` Extension
- Use `ctrl+shift+p` and select `CMake: Configure` and after `CMake: Build`

### Linux

- `sudo apt update`
- `sudo apt install libboost-all-dev`
- Install VS-Code
- Add `C/C++ Extension Pack` Extension
- Add `Cmake Tools` Extension
- Use `ctrl+shift+p` and select `CMake: Configure` and after `CMake: Build`

## Libraries

- [Boost](https://www.boost.org/users/download/)
