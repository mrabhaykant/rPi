These are some of the networking commands for the linux.

1. ngrep
   - debian install ```sudo apt install ngrep ```
   - manual ``` man ngrep```
   - basic usage ```sudo ngrep -W none -d any udp and host 192.168.43.72  and dst port 1235 -T ```

2. netstat
   - usually comes pre installed in most of the standard debian based distributions.
   - basic usage ```netstat -an```

3. ifconfig
   - Lets you see the network configuration
