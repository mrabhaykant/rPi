This folder contains different arm toolchains which are used to process the code.

To setup toolchain on your system follow the steps:
- Go to https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
- Then, download the files depending on your operating system.
- **ON Windows**
  - Download ```gcc-arm-none-eabi-9-2020-q2-update-win32.exe ```
  - Download and install the toolchain software 
  - ***NOTE :***\
    Add the PATH to system variable. It will easier to work with.
  
  

- **On Linux** (debian based operating system like ubuntu,debain,etc)
  - Download ```gcc-arm-none-eabi-9-2020-q2-update-x86_64-linux.tar.bz2```
  - Download the linux toolchain ( it will have the extension of tar.bz2)
  - extract the file
  - run the following command in your system terminal whenever you are working with the toolchain
      ```
      export PATH=$PATH:(your_toolchain_directory_address/arm_none_eabi/bin)
      ```
      ```
      echo $PATH
      ```
      
### Format SD card
You will need to format your sd card to FAT-32. 
There is a SdCardFormatterv5_winEN.zip . Extract the zip and install in windows. 
This program works fine on windows 10.\
**NOTE:** ***This will give no warning and will delete everything and format to the selected. \
            IF USED INCORRECTLY IT CAN WIPE OUT YOUR HARD DRIVE.*** 
       
