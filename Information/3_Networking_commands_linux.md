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

4. iptables-legacy
   - For IP packet routing TCP/UDP packet
   - PREROUTING syntax ```-A PREROUTING -i wlan0 -p udp -m udp --dport 1234 -j DNAT --to-destination 192.168.43.202:57400```
   - FORWARD syntax ```-A FORWARD -d 192.168.43.72/32 -i wlan0 -p udp -m udp --dport 1234 -c 0 0 -j ACCEPT```
   - NOTE: Iptables are being replaced by nftables. Translate legacy commands into new nftables.
