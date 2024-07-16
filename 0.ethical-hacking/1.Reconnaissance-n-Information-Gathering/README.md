Social engineering is a technique used to manipulate individuals into revealing sensitive information
or performing actions that may compromise security. It involves exploiting human psychology rather than
technical vulnerabilities. Reconnaissance, on the other hand, refers to the process of gathering information
about a target system or network to identify potential vulnerabilities and weaknesses. It is an essential
step in the planning phase of an attack.

# active information gathering:

- ping [any website url] or nslookup [website url] -> to get ip address of It
- whois [address] -> to get more details about the domain

# passive information gathering:

- using google search
- useful for ip check -> https://ipinfo.info/html/ip_checker.php

# WhatWeb

- whatweb --help => for all commands
- whatweb moontasir.web.app => will tell me loads of info about the given url
- whatweb [url] -v => verbose prettier print
- whatweb [url/ip] --aggression 3 -v --no-errors => using high aggression level

# gathering emails

- harvester and hunter.io
- theHarvester --help => to know all of its commands
- theHarvester -d [domain] -b all
- hunter.io => this website will give more emails (but not free)

# gather more info

- use github open source packages (e.g. search-> information gathering tools github)

## [sherlock](https://github.com/sherlock-project/sherlock)

- hunt down social media accounts by username
- $ sherlock [username username username ...] : to search for multiple usernames

## [phoneinfoga](https://sundowndev.github.io/phoneinfoga/getting-started/usage/)

- phone number information gathering tool (not best for bd)
- $ phoneinfoga scan -n ["phone number"] : to scan a phone number
- $ phoneinfoga serve -p 8080 : to start a web server

## [RED_HAWK](https://github.com/Tuhinshubhra/RED_HAWK?tab=readme-ov-file)

- RED_HAWK is An All In One Tool For Information Gathering, SQL Vulnerability Scannig and Crawling
- $ php rhawk.php : to start the tool
-

## [OSINT](https://securitytrails.com/blog/osint-tools)

### [READ MORE](https://github.com/sundowndev/hacker-roadmap?tab=readme-ov-file)
