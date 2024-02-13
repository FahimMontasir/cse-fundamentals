Social engineering is a technique used to manipulate individuals into revealing sensitive information or performing actions that may compromise security. It involves exploiting human psychology rather than technical vulnerabilities. Reconnaissance, on the other hand, refers to the process of gathering information about a target system or network to identify potential vulnerabilities and weaknesses. It is an essential step in the planning phase of an attack.

# active information gathering:

- ping [any website url] or nslookup [website url] -> to get ip address of It
- whois [address] -> to get more details about the domain

# passive information gathering:

- using google search
- useful for ip check -> https://ipinfo.info/html/ip_checker.php

# tools

## WhatWeb

- whatweb --help => for all commands
- whatweb moontasir.web.app => will tell me loads of info about the given url
- whatweb [url] -v => verbose prettier print
- whatweb [url/ip] --aggression 3 -v --no-errors => using high aggression level

### important note

Alright, we just started introducing ourselves to different tools that are used for information gathering. But it is important to widen our tool collection as much as possible. We want to know different tools that do same things .. Why you might be asking ? Well tools are unreliable, and sometimes one of them will break, or it wont give us result that we want. In that case it is good to have a backup plan just to be able to get information that you want. For example in the next video you will see a scenario where one of the tool fails, and you will notice that we didn't just quit once we got no results with that tool. We found another alternative that gave us the results that we want. So what is important to learn out of this ?
`Sometimes Tools Will Break Or Not Work!`

### more information gathering

- Information Gathering Finished! First step down. But you should never limit yourself to only the tools we cover in the course. There are many more out there and some could be even better for you than these. At this link right here you can take a look at top 25 OSIN (Open Source Intelligence) Tools and feel free to test all of them out! Some of them we have covered, some of them you will need to download but that is how you practice.(Just if you go through all of them, make sure you skip "Nmap" as that is something we cover in great details in the next section):
- https://securitytrails.com/blog/osint-tools
- We also took a look at our own tool used for gathering information, and we got really good results with it! The more we go through the course the more we need to get into creating our own tools as that eventually becomes a part of being an ethical hacker. Here are some good news! At the and of the course we have added bonus sections that cover Python Programming Basics so all of you that never had any programming experience can go through those videos first and then get into the coding projects! But more about that later. Right now we are ready to cover one of the biggest tools Ethical Hackers use which is called Nmap, and we are going to do that in the next section that covers Scanning!
