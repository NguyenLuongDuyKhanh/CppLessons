Do you want me to show you real compiled assembly snippets for both Raspberry Pi 3 (aarch64-linux-gnu-gcc) and Pico (arm-none-eabi-gcc)? That way, you can see the exact difference in emitted instructions.

# g++-arm-linux-gnueabihf
Command: arm-linux-gnueabihf-g++
Use to build for Raspberry Pi 3 32 bit
sudo apt install g++-arm-linux-gnueabihf

# AArch64 cross-compiler 
Command: aarch64-linux-gnu-gcc
Use to build Raspberry Pi 3 64 bit
sudo apt install g++-aarch64-linux-gnu

Command: arm-none-eabi-gcc