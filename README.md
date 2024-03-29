# Turing's Machine Generator
This is a program written in C++, that reproduces the behavior of a Turing's Machine in a given tape filled with symbols. It accepts both machine's and tape's configurations as text files. It can also generate, edit and save them with the default configuration.  
The program uses the Qt framework and the preferred way to edit it's source code, is importing the project into Qt Creator trought the .pro file. There is also the possibility to build the program with CMake.

## User Interface
<p align="center">
  <img src="https://i.imgur.com/KG19Yjk.png" width="24%"/>
  <img src="https://i.imgur.com/TuWGCkb.png" width="24%"/>
  <img src="https://i.imgur.com/cW6lX5u.png" width="24%"/>
  <img src="https://i.imgur.com/Zx0PCBW.png" width="24%"/>
</p>

## Detailed Guide
[PDF with details](https://drive.google.com/file/d/1ZCt0UHkelz0jMjvgJkSuYC6mIxCAzb95/view?usp=sharing)

## Executable
[Windows](https://drive.google.com/open?id=162AiHEm7-ugQmCrp6abZ4_EKJGZ1K9BQ)  -  Extract and execute TuringsMachineGenerator.exe

## Build with CMake
- git clone https://github.com/fabioalves98/TuringsMachineGenerator.git  -> Clones the repository
- cd TuringsMachineGenerator/  -> Enters the project folder
- cmake .  -> Generates the Makefile
- make  -> Compiles the source code
- ./TuringsMachineGenerator  -> Executes the program
