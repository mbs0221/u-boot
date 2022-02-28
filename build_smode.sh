#!/bin/bash -v

make CROSS_COMPILE=riscv64-unknown-linux-gnu- rocketchip_vc709_defconfig
make CROSS_COMPILE=riscv64-unknown-linux-gnu- ARCH=riscv
