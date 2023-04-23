# INTRODUCTION

This is a "hello world" program for the [GNU Multiple Precision Arithmetic Library](https://gmplib.org) on Windows. It includes installation steps and an example C++ program.

--------------------

# MSYS2 INSTALLATION

Install MSYS2 from https://www.msys2.org

Run msys2.exe, which opens a terminal. Install packages by running:

<code> pacman -S [PACKAGE NAME] </code>

I installed these packages:
 - mingw-w64-x86_64-gcc  (gcc/g++ compilers)
 - mingw-w64-x86_64-gdb  (debugger)
 - mingw-w64-x86_64-gmp  (multiprecision library)
 - mingw-w64-x86_64-make (build utility)

Add an environment variable, <code>MINGW64_HOME</code>, whose value is the path to the mingw64 folder (C:\msys64\mingw64). 

Also add the mingw64/bin folder to PATH. Finally, compile by running <code>make</code>


# CYGWIN INSTALLATION

Installation steps:

- Install 7zip
- Install Cygwin, add the following packages to the default installation
    gcc-core
    gcc-g++
    libgcc
    m4
    make
    cmake
    bash

- download gmp.tar.xz from https://gmplib.org, then unzip it and place its contents in C:/gmp
- Launch bash.exe from C:\cygwin64\bin
- change directory to the gmp folder
- Execute: ./configure --enable-cxx
- Execute: make
- Execute: make install
- Execute: make check

Now C:\gmp\.libs should have some .a and .la files. We link and compile by running:

<code> g++ hello.cpp -I "C:\gmp" -L"C:\gmp\.libs" -lgmp -lgmpxx -o hello </code>

This worked but I had a problem getting it to work with gdbgui (a GUI for the gdb debugger). 
It was failing to locate files using cygwin's UNIX-style file system
