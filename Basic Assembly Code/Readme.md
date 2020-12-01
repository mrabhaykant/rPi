These codes are very basic and intended for use with raspberry pi 3b+

### Peripheral Addresses of raspberry pi 3 b+
![Peripheral addresses](https://github.com/mrabhaykant/rPi/blob/main/Basic%20Assembly%20Code/rpi%203b+%20peripheral%20address.jpg)<br />
These are the base addresses you have to ADD your location to reach the specific peripheral location.

```
Example:
Base adress = 0x0200
example_bit_location = 0x02
so, 
you need to access
 0x0200   //This is your Base Address
+0x0020   //Peripheral location
---------
=0x0220   //Actual Location that you need to access

```
