## What is scanning and how it is different from information gathering?

Scanning is the process where you interact directly with a system to discover open ports, live systems,
various services running on the hosts. You might use tools like Nmap or Nessus to perform this task. The
goal is to understand what kind of doors into the system are open.
Information Gathering, also known as reconnaissance, is the first step in the process where you collect as
much information as possible about the target, but without directly interacting with the system. This could
involve searching public databases, social media, WHOIS records, DNS records, etc. The goal is to
understand the target environment and its potential vulnerabilities.
In summary, the main difference is that information gathering is passive and doesn't interact with the
target system, while scanning is active and directly interacts with the system.

## What is TCP and UDP?

TCP (Transmission Control Protocol) and UDP (User Datagram Protocol) are two of the most commonly used
protocols in the Internet Protocol Suite. They both work at the transport layer of the TCP/IP model and
serve as communication protocols for sending packets of data across networks.

TCP (Transmission Control Protocol) is a connection-oriented protocol that provides reliable, ordered,
and error-checked delivery of a stream of packets on the internet. It is heavy-duty, ensuring that all
packets reach their destination in the correct order. This is used when it is essential that every bit
of data is received correctly, such as web pages, databases, etc.

- Connection-oriented: Yes
- Reliable: Yes
- Ordered: Yes
- Speed: Slower than UDP
- Use cases: Web servers, database servers, mail servers, etc.

UDP (User Datagram Protocol) is a connectionless protocol that sends packets without establishing a
connection and without checking if they are received. It is lightweight but less reliable. It's used
when speed is desirable and error correction isn't necessary, such as streaming audio and video.

- Connection-oriented: No
- Reliable: No
- Ordered: No
- Speed: Faster than TCP
- Use cases: Streaming media (video, audio), online multiplayer games, Voice over IP (VoIP)

## tools for scanning

### arp (Address Resolution Protocol):

arp is a command-line utility that displays and modifies the Address Resolution Protocol (ARP) cache.

- arp --help : Display help message
- arp -a : Display all the hosts

### netdiscover:

- netdiscover : Discovers hosts / devices on the network

### nmap:

##### [namp cheatsheet](https://zerotomastery.io/cheatsheets/nmap-cheat-sheet/?utm_source=udemy&utm_medium=coursecontent)

nmap is a free and open-source network scanner created by Gordon Lyon. It is used to discover hosts and
services on a computer network, thus creating a "map" of the network. To accomplish its goal, nmap sends
specially crafted packets to the target host and then analyzes the responses.

- nmap --help : Display help message
- nmap [ip/network] : Scan a single IP address
- nmap -sS [ip/network] : Perform a TCP SYN scan
- name -sT [ip/network] : Perform a TCP connect scan (perform full tcp connection)
- nmap -sU [ip/network] : Perform a UDP scan
- man nmap : Display the manual page for nmap
