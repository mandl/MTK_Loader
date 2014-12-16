GNU ARM Cross-Toolchain Builder

Builds GNU ARM Cross-Toolchain from Scratch

  Target: ARM MT6223

 Features:
- GNU C (4.9.1)
-  with newlib (2.1.0)
- GNU C++ (4.9.1, implements: C++14, C++11)
-  with libstdc++ (4.9.1)
- GDB (7.8)


- This script is copied from 

https://github.com/istarc/stm32.git

Build

Copy build.sh and newlib-2.1.0.patch in a empty folder

start ./build.sh 

wait ..... 

To toolchain will be found in ~/arm_5t
