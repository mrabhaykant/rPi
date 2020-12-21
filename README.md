# rPi
Raspberry Pi 3 b+ Codes

This repo contains the code that operates on the raspberry pi 3 b+.
I have found the bare metal codes on internet. Using those I am 
trying to understand ARM.

**To Do List**
- [ ] Record video of setup
- [ ] compile c without standard libraries
- [ ] led on every gpio as output  
- [ ] mmap linux
- [ ] GPU postman working

### Board Specifications

- GPU :         
  - Videocore IV
- Processor:      
  - Broadcom BCM28730B0
  - Cortex-A53 (ARMv8) 64-bit SoC @ 1.4 Ghz
- RAM	 : 
  - 1 GB LPDDR2 SDRAM
- Communication:  
  - 2.4GHz and 5GHz IEEE 802.11/b/n/ac wireless LAN
  - Bluetooth 4.2
  - BLE
  - Ethernet Gigabit over USB 2.0 (Max. throughtput 300 Mbps)
  - USB 2.0 ( 4 PORT )
- GPIO	 :        40 PIN 
- Video	 :
  - HDMI (Full-Size)
  - DSI display port for connecting a rPi touchscreen display
  - 4-pole setreo output and composite video port

#### Folder Details

**sd_card_content :**\
This folder contains the file that should be on every FAT-32 formated Sd-card or USB pen drive.
Without these files the sd card would not be recognised in the raspberry pi.

**Basic Assembly Code :**\
This directory contains different sub-directories which contains codes to operate different peripheral on raspberry pi 3 b+.<br />
Each folder contains a readme file which contains almost all the details regarding it's respective content.

***Information :***\
This directory contains different information regarding raspberry pi.

**Datasheets :**\
Different datasheets regarding this project goes here.
