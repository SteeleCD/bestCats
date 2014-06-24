#!/bin/bash

#sudo apt-get install mingw32 

  

# for 32 bit

#sudo yum install mingw32-gcc-c++

i686-w64-mingw32-g++ ../main.cpp ../catDatabase.cpp -o bestCats_32.exe -static-libgcc -static-libstdc++

# for 64 bit

#sudo yum install mingw64-gcc-c++

x86_64-w64-mingw32-g++ ../main.cpp ../catDatabase.cpp -o bestCats_64.exe -static-libgcc -static-libstdc++
