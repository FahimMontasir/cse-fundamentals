# Cloud Computing

## Digital Ocean

### Digital ocean is IAAS (Infrastructure as a Service) provider

- gives raw infrastructure

### AWS vs Google Cloud vs Digital Ocean

- less feature but has most used
- Digital Ocean space is similar to aws s3
- clean and sleek interface
- upfront pricing (no difficulties of pricing, no hidden cost)
- cost less, no downtime and fast

### Heroku vs Digital Ocean

- Heroku is PAAS (Platform as a Service) provider not IAAS
- Larger pricing, easy setup and solution

### Godaddy/Namecheap vs Digital Ocean

- completely managed solution (except vps)
- not good for learning as a developer

### What is a droplet?

- virtual machine(computer) connected to internet
- has a public ip address
- similar to vps

### Droplet Config

- do not select autobackup cz you can write a simple script to backup your database to google drive
- use ubuntu
- use ssh keys (generate using git bash)
- ssh -i (private key path) root@droplet_ip [to get access of the droplet inside your local machine]
- free -h [to check memories]

### Firewall

- networking -> firewall
- network layer
- does not even reach droplet
- rules in Firewall -> tcp/udp
