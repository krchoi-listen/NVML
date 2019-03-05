# NVML
It is an NVML test program, and it shows account status.

This program uses nvml library, which is distributed by NVidia.

My concern is acquiring GPU usage metric by using "nvmlDeviceGetAccountingStats" function.

How to build:

make

How to run: This program requires root authority because it tries to change accounting mode.

sudo ./smi
