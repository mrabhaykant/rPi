These are some commands which works in linux for debugging purpose.

1. Hex Dump
   - syntax ```hd [filename] ```
   - manual ```man hd```

2. watch command
   - Lets you view the changes in the commands
   - example: if you want to see the changes in the directory content. you could use something like ```watch -n 1 ls -al```
   - syntax ``` watch {options} (command [command option] )```

3. Install a package in debian
   - ```.deb```
     - To install chnage your directory to the where that installation file is stored
     - ```sudo dpkg --install YOUR-FILE_NAME.deb-GOES-HERE```
   - ```.sh```
     -  To install chnage your directory to the where that installation file is stored
     -  ```sudo sh ./FileName.sh```
    
