# General-RTOS

Hi there, welcome to grtos, a general run time operating system library.

This is a library created to make an RTOS that could be personalised for different types of microcontroller. The goal of this library is to create a structure that would resemble the one of an RTOS by incorporating key options that would normally be present in an RTOS.

## Installation
The first thing that you will want to do is to copy this repo! To do that, you can use this command line:
```bat
git clone https://github.com/ThierryBeaulieu/General-RTOS.git
```
The first thing that you should know of is that this library depends on [CMake](https://cmake.org/install/). Therefore, you should make sure to have it installed. To incorporate the grtos library to a project, you could simply add the ```grtos``` folder to your files and link it using the instruction ```add_subdirectory(grtos)``` inside your CMakeLists.txt.

## Structure

![grtos_thierrys_version drawio](https://user-images.githubusercontent.com/46804791/208923876-aeaea3e8-e0a3-41ea-8369-c800b744fcf1.png)

