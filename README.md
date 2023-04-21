# msp430-gcc-9.3.1.11

This repo contains the `msp430-gcc-9.3.1.11-source-full` sources published by TI, in addition to a fix for a linker bug that can cause corrupt DWARF debug information to be output when LTO is enabled. See commit `7d61031`.

### Building

To build for Linux, simply run:

    ./README-build.sh

and the gcc toolchain will be compiled to `msp430-gcc-9.3.1.11/install/usr/local/bin`.
