# Dynamic-Kernel-Module

**1. Going to a related directory and buiding executable programs and libraries from source code by reading files called Makefile.**

        cd Directory-Kernel-Module/
        make

**2. Inserting a module into the kernel by passing a PID of process as an argument (_Enter PID ,which is valid in your kernel, as argument. I gave 1299 in my execution_).**

        sudo insmod main.ko processID=1299
        
**3. Displaying kernel-related messages.**

        sudo dmesg

**4. Removing a module.**

        sudo rmmod main.ko
        
**5. Displaying kernel-related messages after removing module.**

        sudo dmesg

**6. Removing all the object files that had been created in the meantime.**

        make clean
