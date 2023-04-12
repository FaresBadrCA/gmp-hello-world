=======================================================
CYGWIN INSTALLATION
=======================================================

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

- download gmp.tar.xz from https://gmplib.org/, then unzip it and place its contents in C:/gmp
- Launch bash.exe from C:\cygwin64\bin
- change directory to the gmp folder
- Execute: ./configure --enable-cxx
- Execute: make
- Execute: make install
- Execute: make check

Now C:\gmp\.libs should have some .a and .la files, which we link to by calling:

g++ hello.cpp -I "C:\gmp" -L"C:\gmp\.libs" -lgmp -lgmpxx -o hello 

This worked but I had a problem getting it to work with gdbgui (a GUI for the gdb debugger). 
It was failing to locate files using cygwin's UNIX-style file system

=========================================================
MSYS2 INSTALLATION
=========================================================

I found MSYS2 to work much more easily than Cygwin. Install MSYS2 from https://www.msys2.org/

I run msys2.exe, which opens a terminal. In there, I run: pacman -Ss <PACKAGE NAME>
to search for packages, and then pacman -S <PACKAGE NAME> to install it

I installed these packages: (names here are not exact, use the search function to get the
	- mingw-w64-x86_64-gcc  (gcc/g++ compilers)
	- mingw-w64-x86_64-gdb  (debugger)
	- mingw-w64-x86_64-gmp  (multiprecision library)
	- mingw-w64-x86_64-make (build utility)

Then the gcc/g++ compilers are in mingw64\bin
The gmp statically-linked libraries are in mingw64\lib
Lastly, the gmp.h/gmpxx.h header files are in mingw64\include

g++ hello.cpp -I "C:\msys64\mingw64\include" -L "C:\msys64\mingw64\lib" -lgmp -lgmpxx -o hello
