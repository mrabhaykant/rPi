# Startup sequence of raspberry pi 3 b +

The raspberry pi does not start the reading and executing instructions from the SD card.
It first starts the GPU. Then it loads the drivers related to the GPU. 
Then it checks for the sd card. If there is a sd card then it loads the memory from the sd card.
If there is no sd card then it checks the usb for pen drive.

You can not access the videocore GPU of the raspberry pi. It a closed source system and 
raspberry pi has not issued any specific information regarding it.

You can not brick the raspberry pi easily because it first loads the gpu and driver and
then it starts reading from the sd cards. So you your code will come later on and it will
be executed by then.<br />
So each time the raspberry pi start it loads the initial values from its internal storages.
The initialization values even if you change them in your code gets reset at the power on.
