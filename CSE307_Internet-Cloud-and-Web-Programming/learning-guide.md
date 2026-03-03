# Cloud Infrastructure & DevOps Learning Guide

**Learn by doing** — This guide teaches you cloud infrastructure and DevOps engineering by walking through the actual implementation in this repository. Start from the beginning and progress step-by-step. Each concept is explained with real code examples from this project.

---

## 📚 Table of Contents

1. [What Is Cloud Infrastructure?](#1-what-is-cloud-infrastructure)
2. [AWS Foundations — Regions, Availability Zones, Core Services](#2-aws-foundations--regions-availability-zones-core-services)
3. [Networking on AWS — VPC, Subnets, Load Balancers, DNS](#3-networking-on-aws--vpc-subnets-load-balancers-dns)
4. [Compute — Containers, Docker, ECS Fargate](#4-compute--containers-docker-ecs-fargate)
5. [Databases & Storage — RDS, Redis, S3, EFS](#5-databases--storage--rds-redis-s3-efs)
6. [Infrastructure as Code — Terraform Fundamentals](#6-infrastructure-as-code--terraform-fundamentals)
7. [Terraform Advanced — Modules, State Management, Multi-Provider](#7-terraform-advanced--modules-state-management-multi-provider)
8. [Secrets & IAM Security — SSM, Roles, Least Privilege](#8-secrets--iam-security--ssm-roles-least-privilege)
9. [CDN, TLS & Frontend Delivery — CloudFront, ACM](#9-cdn-tls--frontend-delivery--cloudfront-acm)
10. [DevOps Practices — CI/CD, Versioning, Cost Management, Observability](#10-devops-practices--cicd-versioning-cost-management-observability)

---

## 1. What Is Cloud Infrastructure?

### 🧠 The Concept

**Infrastructure** traditionally meant physical servers in a data center — machines, cables, power supplies, cooling systems, network equipment. You'd buy hardware, install it in racks, configure networking, and manually deploy your applications.

**Cloud Infrastructure** means renting computing resources (servers, databases, storage) from a provider over the internet. Instead of buying and maintaining physical hardware, you provision virtual resources on-demand through code or a web interface.

### 🎯 Mental Model

Think of it like **housing**:
- **Traditional Infrastructure** = Buying land, building your own house, maintaining plumbing, electricity, heating
- **Cloud Infrastructure** = Renting an apartment — you get instant access to utilities, and you only pay for what you use

### 📂 In This Codebase

Look at [plan.md](../plan.md) — this document describes the **architecture philosophy**:
- "Single Source of Truth" — all infrastructure defined in one place
- "Modularity" — reusable building blocks
- "Environments" — separate dev/prod configurations

The [README.md](../README.md) shows two environments:
```
| Environment     | CLI         | URLs                                     |
| --------------- | ----------- | ---------------------------------------- |
| **Development** | `./kc`      | dev-app.kuno-ai.com, dev-api.kuno-ai.com |
| **Production**  | `./kc-prod` | app.kuno-ai.com, api.kuno-ai.com         |
```

This means:
- You have **two identical copies** of your infrastructure (dev and prod)
- Dev is for testing; prod serves real users
- Both are defined using the same code, just with different parameters

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **Infrastructure as Code (IaC)** | Managing infrastructure using config files instead of manual clicking |
| **Cloud Provider** | Company that rents computing resources (AWS, Google Cloud, Azure) |
| **Environment** | An isolated copy of your infrastructure (dev, staging, production) |
| **Region** | Geographic location where cloud resources physically exist |

### 📖 Further Learning

**Blog Posts:**
- [What Is Cloud Computing? - AWS Official](https://aws.amazon.com/what-is-cloud-computing/)
- [Infrastructure as Code Explained - HashiCorp](https://www.hashicorp.com/resources/what-is-infrastructure-as-code)
- [Dev, Staging, and Production Environments](https://dev.to/flippedcoding/difference-between-development-stage-and-production-d0p)

**Videos:**
- [Cloud Computing Explained in 6 Minutes - Fireship](https://www.youtube.com/watch?v=M988_fsOSWo)
- [DevOps Roadmap 2024 - TechWorld with Nana](https://www.youtube.com/watch?v=9pZ2xmsSDdo)

---

## 2. AWS Foundations — Regions, Availability Zones, Core Services

### 🧠 The Concept

**Amazon Web Services (AWS)** is the largest cloud provider. They operate data centers around the world organized into:

1. **Regions** — Geographic areas (e.g., Paris, Virginia, Tokyo)
2. **Availability Zones (AZs)** — Isolated data centers within a region (usually 2-6 per region)
3. **Services** — Building blocks you can rent (compute, storage, databases, networking)

AWS has **200+ services**, but most applications use only 10-15 core services.

### 🎯 Mental Model

Think of AWS like a **global hardware store**:
- **Regions** = Different store locations (Paris branch, Tokyo branch)
- **Availability Zones** = Warehouses at each location (if one catches fire, others keep running)
- **Services** = Items on the shelves (you pick what you need and rent it)

### 📂 In This Codebase

#### Region Selection
Multiple files set the region to **eu-west-3** (Paris, France):

[kc](../kc) line 11:
```bash
export AWS_REGION=${AWS_REGION:-"eu-west-3"}
```

[kc-prod](../kc-prod) line 16:
```bash
export AWS_REGION=${AWS_REGION:-"eu-west-3"}
```

**Why Paris?** Likely chosen for:
- Proximity to European users (lower latency)
- GDPR compliance (data stays in EU)
- Lower costs than some other EU regions

#### Availability Zones
[modules/vpc/main.tf](../modules/vpc/main.tf) lines 12-26:
```hcl
# Public Subnets (2 AZs for high availability)
resource "aws_subnet" "public_subnet_1" {
  availability_zone = "${var.region}a"  # eu-west-3a
  ...
}

resource "aws_subnet" "public_subnet_2" {
  availability_zone = "${var.region}b"  # eu-west-3b
  ...
}
```

This creates resources in **two different AZs** (`eu-west-3a` and `eu-west-3b`). If one data center fails, the other keeps running.

#### AWS Services Used
This project uses **23 AWS services**:

| Category | Services |
|---|---|
| **Compute** | ECS (Elastic Container Service), ECR (Container Registry), Lambda (implied) |
| **Networking** | VPC, ALB (Load Balancer), Route53 (DNS), CloudFront (CDN) |
| **Storage** | S3 (Object Storage), EFS (File System) |
| **Database** | RDS (PostgreSQL), ElastiCache (Redis) |
| **Security** | IAM (Identity), ACM (SSL Certificates), Secrets Manager, SSM Parameter Store |
| **Observability** | CloudWatch (Logs/Metrics), SNS (Notifications) |
| **Cost** | Budgets, Cost Explorer |
| **AI** | Bedrock (Foundation Models) |
| **Other** | DynamoDB (State Locking), Cloud Map (Service Discovery) |

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **Region** | Physical location with multiple data centers (e.g., `eu-west-3` = Paris) |
| **Availability Zone (AZ)** | Isolated data center within a region (e.g., `eu-west-3a`) |
| **Multi-AZ** | Deploying resources across multiple AZs for fault tolerance |
| **Service** | A specific AWS product you can use (ECS, S3, RDS, etc.) |
| **ARN** | Amazon Resource Name — unique ID for any AWS resource |

### 📖 Further Learning

**Blog Posts:**
- [AWS Global Infrastructure](https://aws.amazon.com/about-aws/global-infrastructure/)
- [Regions and Availability Zones Explained](https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/using-regions-availability-zones.html)
- [AWS Service Comparison Cheat Sheet](https://tutorialsdojo.com/aws-cheat-sheets/)

**Videos:**
- [AWS Regions and AZs Explained - StéphaneMaarek](https://www.youtube.com/watch?v=14zB6fY-JFk)
- [Top 50 AWS Services Explained in 10 Minutes - Fireship](https://www.youtube.com/watch?v=JIbIYCM48to)
- [AWS Certified Cloud Practitioner Full Course - freeCodeCamp](https://www.youtube.com/watch?v=SOTamWNgDKc)

---

## 3. Networking on AWS — VPC, Subnets, Load Balancers, DNS

### 🧠 The Concept

Cloud networking creates a **private network in the cloud** that mimics a traditional office network:
- **VPC (Virtual Private Cloud)** = Your private network space
- **Subnets** = Segments within your network
- **Security Groups** = Firewall rules controlling traffic
- **Load Balancer** = Traffic distributor to multiple servers
- **DNS** = Translates domain names to IP addresses

### 🎯 Mental Model

Think of it like an **office building**:
- **VPC** = The entire building (locked doors, private space)
- **Public Subnet** = Lobby/reception (visitors can enter)
- **Private Subnet** = Back offices (only employees can access)
- **Security Group** = Security badge requirements (who can enter which room)
- **Load Balancer** = Receptionist directing visitors to available staff

### 📂 In This Codebase

#### VPC Architecture
[modules/vpc/main.tf](../modules/vpc/main.tf) creates the entire network:

```hcl
# The VPC - your private network
resource "aws_vpc" "main" {
  cidr_block           = var.vpc_cidr  # e.g., "10.0.0.0/16"
  enable_dns_hostnames = true
  enable_dns_support   = true
}
```

**CIDR blocks** define IP address ranges:
- Dev: `10.0.0.0/16` = 65,536 addresses (10.0.0.0 to 10.0.255.255)
- Prod: `10.1.0.0/16` = 65,536 addresses (10.1.0.0 to 10.1.255.255)

Different ranges allow future **VPC peering** (connecting dev and prod networks).

#### Subnets: Public vs Private
[modules/vpc/main.tf](../modules/vpc/main.tf) lines 12-45:

**Public Subnets** (Internet-accessible):
```hcl
resource "aws_subnet" "public_subnet_1" {
  vpc_id                  = aws_vpc.main.id
  cidr_block              = var.public_subnet_cidrs[0]  # e.g., "10.0.1.0/24"
  availability_zone       = "${var.region}a"
  map_public_ip_on_launch = true  # Auto-assign public IPs
}
```

Used for:
- ECS containers running web servers
- Application Load Balancers

**Private Subnets** (No direct Internet access):
```hcl
resource "aws_subnet" "private_subnet_1" {
  vpc_id            = aws_vpc.main.id
  cidr_block        = var.private_subnet_cidrs[0]  # e.g., "10.0.101.0/24"
  availability_zone = "${var.region}a"
  # No public IP assignment
}
```

Used for:
- RDS PostgreSQL database
- ElastiCache Redis

#### Internet Gateway & NAT Gateway
[modules/vpc/main.tf](../modules/vpc/main.tf) lines 47-81:

**Internet Gateway** (IGW):
```hcl
resource "aws_internet_gateway" "main" {
  vpc_id = aws_vpc.main.id
}
```
- Allows public subnets to reach the Internet
- Like the building's main entrance

**NAT Gateway** (Network Address Translation):
```hcl
resource "aws_nat_gateway" "main" {
  count         = var.enable_nat_gateway ? 1 : 0
  allocation_id = aws_eip.nat[0].id
  subnet_id     = aws_subnet.public_subnet_1.id
}
```
- Allows private subnets to make *outbound* requests to the Internet
- Blocks *inbound* requests from the Internet
- Like a mail room — employees can send mail, but random people can't walk in

#### Load Balancer
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 31-49:

```hcl
resource "aws_lb" "main" {
  name               = "${var.project_name}-${var.service_name}-alb"
  internal           = false  # Internet-facing
  load_balancer_type = "application"
  security_groups    = [aws_security_group.alb_sg.id]
  subnets            = var.public_subnet_ids
}
```

**What it does:**
1. Receives traffic on `dev-api.kuno-ai.com:443` (HTTPS)
2. Distributes traffic to ECS containers
3. Performs health checks (`/health` endpoint)
4. Automatically routes to healthy containers only

#### Security Groups (Firewall Rules)
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 1-29:

**ALB Security Group** (allow Internet traffic):
```hcl
resource "aws_security_group" "alb_sg" {
  name = "${var.project_name}-${var.service_name}-alb-sg"
  
  ingress {
    from_port   = 80
    to_port     = 80
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]  # Anyone on the Internet
  }
  
  ingress {
    from_port   = 443
    to_port     = 443
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]  # Anyone on the Internet
  }
}
```

**ECS Task Security Group** (only allow ALB):
```hcl
resource "aws_security_group" "ecs_task_sg" {
  name = "${var.project_name}-${var.service_name}-ecs-task-sg"
  
  ingress {
    from_port       = var.container_port
    to_port         = var.container_port
    protocol        = "tcp"
    security_groups = [aws_security_group.alb_sg.id]  # ONLY the ALB
  }
}
```

This is **security group chaining** — containers only accept traffic from the load balancer, not directly from the Internet.

#### DNS with Route53
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 172-181:

```hcl
data "aws_route53_zone" "main" {
  name = var.domain_name  # "kuno-ai.com"
}

resource "aws_route53_record" "api" {
  zone_id = data.aws_route53_zone.main.zone_id
  name    = var.service_domain  # "dev-api.kuno-ai.com"
  type    = "A"
  
  alias {
    name                   = aws_lb.main.dns_name
    zone_id                = aws_lb.main.zone_id
    evaluate_target_health = true
  }
}
```

**What this does:**
- Creates DNS record `dev-api.kuno-ai.com` → points to Load Balancer
- Users type `dev-api.kuno-ai.com` in browser
- Route53 returns the Load Balancer's IP address
- Browser connects to Load Balancer
- Load Balancer forwards to ECS containers

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **VPC** | Virtual Private Cloud — your isolated network in AWS |
| **CIDR** | Classless Inter-Domain Routing — notation for IP ranges (e.g., `10.0.0.0/16`) |
| **Subnet** | A segment of a VPC with its own IP range |
| **Public Subnet** | Subnet with Internet access (via Internet Gateway) |
| **Private Subnet** | Subnet without direct Internet access |
| **Security Group** | Virtual firewall controlling inbound/outbound traffic |
| **ALB** | Application Load Balancer — distributes HTTP/HTTPS traffic |
| **NAT Gateway** | Allows private resources to make outbound Internet requests |
| **Route53** | AWS DNS service (routes domain names to IP addresses) |
| **DNS** | Domain Name System — translates `kuno-ai.com` to IP address |

### 📖 Further Learning

**Blog Posts:**
- [AWS VPC Beginner to Pro](https://dev.to/aws-builders/aws-vpc-beginner-to-pro-4k50)
- [Understanding CIDR Notation](https://www.ionos.com/digitalguide/server/know-how/cidr-classless-inter-domain-routing/)
- [Public vs Private Subnets Explained](https://docs.aws.amazon.com/vpc/latest/userguide/configure-subnets.html)
- [Security Groups Best Practices](https://docs.aws.amazon.com/vpc/latest/userguide/vpc-security-best-practices.html)

**Videos:**
- [AWS VPC & Subnets Explained - TechWorld with Nana](https://www.youtube.com/watch?v=bGDMeD6kOz0)
- [What is a Load Balancer? - IBM Technology](https://www.youtube.com/watch?v=sCR3SAVdyCc)
- [DNS Explained in 100 Seconds - Fireship](https://www.youtube.com/watch?v=UVR9lhUGAyU)
- [AWS Networking Fundamentals - freeCodeCamp](https://www.youtube.com/watch?v=hiKPPy584Mg)

---

## 4. Compute — Containers, Docker, ECS Fargate

### 🧠 The Concept

**Traditional servers** run one application per machine. **Containers** package an application and all its dependencies into a portable unit that runs consistently anywhere.

**Docker** is the most popular container technology. **ECS (Elastic Container Service)** is AWS's service for running Docker containers at scale. **Fargate** is a serverless mode where AWS manages the servers for you.

### 🎯 Mental Model

Think of containers like **shipping containers**:
- **Traditional Deployment** = Loading cargo piece-by-piece onto a truck (fragile, slow, inconsistent)
- **Containers** = Standardized shipping containers (stack anywhere, move between ships/trains/trucks easily)

**ECS Fargate** = You provide the container (your app), AWS provides the truck, driver, and logistics.

### 📂 In This Codebase

#### Docker Images
This project has **three containerized services**:

1. **Backend** (Node.js/TypeScript API)
2. **RAG1** (Python/FastAPI AI service)
3. **Qdrant** (Vector database)

Each is built from a **Dockerfile** (not in this repo — in the application repos). The built images are stored in **ECR (Elastic Container Registry)**.

#### ECR Image Management
[cli/deploy-app.sh](../cli/deploy-app.sh) lines 47-94:

```bash
# Get ECR repository URL
REPO_URL=$(aws ecr describe-repositories \
  --repository-names kuno/${SERVICE} \
  --query 'repositories[0].repositoryUri' \
  --output text)

# Build Docker image (cross-platform for AWS)
docker build --platform linux/amd64 \
  -t ${REPO_URL}:${NEW_VERSION} \
  -t ${REPO_URL}:latest \
  -f ${DOCKERFILE} \
  ${BUILD_CONTEXT}

# Push to ECR
docker push ${REPO_URL}:${NEW_VERSION}
docker push ${REPO_URL}:latest
```

**Key points:**
- `--platform linux/amd64` — AWS runs Intel/AMD chips, not ARM (important for M1/M2/M3 Macs)
- **Multi-tagging** — same image gets `latest`, `1.2.3`, and `20230226-103000-abc1234` tags
- **ECR authentication** — requires `aws ecr get-login-password` before pushing

#### ECS Fargate Task Definition
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 120-158:

```hcl
resource "aws_ecs_task_definition" "task" {
  family                   = "${var.project_name}-${var.service_name}"
  requires_compatibilities = ["FARGATE"]
  network_mode             = "awsvpc"  # Each task gets its own IP
  cpu                      = var.task_cpu          # e.g., "256" = 0.25 vCPU
  memory                   = var.task_memory       # e.g., "512" = 512 MB RAM
  execution_role_arn       = var.execution_role_arn
  task_role_arn            = var.task_role_arn
  
  container_definitions = jsonencode([
    {
      name      = var.service_name
      image     = "${var.ecr_repository_url}:${var.image_tag}"
      cpu       = var.task_cpu
      memory    = var.task_memory
      essential = true
      
      portMappings = [{
        containerPort = var.container_port  # e.g., 3000 for backend
        protocol      = "tcp"
      }]
      
      environment = [
        for key, value in var.environment_variables : {
          name  = key
          value = value
        }
      ]
      
      secrets = [
        for key, value in var.secrets : {
          name      = key
          valueFrom = value  # SSM Parameter ARN
        }
      ]
      
      healthCheck = {
        command     = ["CMD-SHELL", "curl -f http://localhost:${var.container_port}/health || exit 1"]
        interval    = 30
        timeout     = 5
        retries     = 3
        startPeriod = 60
      }
      
      logConfiguration = {
        logDriver = "awslogs"
        options = {
          "awslogs-group"         = "/ecs/${var.project_name}-${var.service_name}"
          "awslogs-region"        = var.region
          "awslogs-stream-prefix" = "ecs"
        }
      }
    }
  ])
}
```

**What this defines:**
- **Image**: Which Docker image to run (from ECR)
- **Resources**: How much CPU/memory to allocate
- **Ports**: Which port the container listens on
- **Environment Variables**: Configuration (API URLs, feature flags)
- **Secrets**: Sensitive values (pulled from SSM Parameter Store)
- **Health Check**: How to verify the container is working
- **Logs**: Where to send logs (CloudWatch)

#### ECS Service
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 160-190:

```hcl
resource "aws_ecs_service" "service" {
  name            = "${var.project_name}-${var.service_name}-service"
  cluster         = var.cluster_id
  task_definition = aws_ecs_task_definition.task.arn
  desired_count   = var.desired_count  # How many containers to run
  launch_type     = "FARGATE"
  
  network_configuration {
    subnets          = var.private_subnet_ids
    security_groups  = [aws_security_group.ecs_task_sg.id]
    assign_public_ip = true  # Needed for pulling ECR images
  }
  
  load_balancer {
    target_group_arn = aws_lb_target_group.main.arn
    container_name   = var.service_name
    container_port   = var.container_port
  }
  
  health_check_grace_period_seconds = 120
  
  enable_execute_command = true  # Allows SSH-like access via ECS Exec
}
```

**What this does:**
- Runs `desired_count` copies of the container
- Connects them to the Load Balancer
- Replaces unhealthy containers automatically
- Registers/deregisters containers from the target group

#### ECS Exec (SSH into Containers)
[kc](../kc) lines 738-768:

```bash
exec_command() {
  local command=$1
  local cluster_name="${CLUSTER_NAME:-kuno-main-cluster}"
  local service_name="${SERVICE_PREFIX:-kuno-main}-backend-service"
  
  # Get running task ID
  task_arn=$(aws ecs list-tasks \
    --cluster "$cluster_name" \
    --service-name "$service_name" \
    --query 'taskArns[0]' \
    --output text)
  
  # Execute command inside container
  aws ecs execute-command \
    --cluster "$cluster_name" \
    --task "$task_arn" \
    --container backend \
    --interactive \
    --command "$command"
}
```

**Usage:**
```bash
./kc exec 'bash'                # Open a shell
./kc exec 'env | grep DATABASE' # Check environment variables
./kc exec 'curl localhost:3000/health'  # Test endpoint
```

#### Environment-Specific Configuration
[environments/dev/main.tf](../environments/dev/main.tf) lines 132-145:

```hcl
module "kuno_backend_service" {
  source = "../../modules/ecs_service"
  # ... other config ...
  task_cpu    = "256"   # 0.25 vCPU
  task_memory = "512"   # 512 MB
}

module "rag1_service" {
  source = "../../modules/ecs_service"
  # ... other config ...
  task_cpu    = "1024"  # 1 full vCPU
  task_memory = "2048"  # 2 GB
}
```

**Why different sizes?**
- Backend is lightweight (API routing, database queries)
- RAG1 loads ML models into memory (needs more resources)

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **Container** | Packaged application with all dependencies, runs consistently anywhere |
| **Docker** | Most popular container technology |
| **Docker Image** | Snapshot of a container (like a .zip file) |
| **Dockerfile** | Recipe for building a Docker image |
| **ECR** | Elastic Container Registry — AWS's Docker image storage |
| **ECS** | Elastic Container Service — AWS service for running containers |
| **Fargate** | Serverless ECS mode (AWS manages servers) |
| **Task Definition** | Blueprint for running a container (image, CPU, memory, env vars) |
| **ECS Service** | Maintains desired number of running containers |
| **ECS Exec** | SSH-like access to running containers |

### 📖 Further Learning

**Blog Posts:**
- [Docker Explained Simply](https://www.freecodecamp.org/news/docker-simplified-96639a35ff36/)
- [Containers vs VMs](https://www.docker.com/resources/what-container/)
- [AWS ECS vs EKS vs Fargate](https://aws.amazon.com/blogs/containers/amazon-ecs-vs-amazon-eks-making-sense-of-aws-container-services/)
- [ECS Task Definition Deep Dive](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/task_definitions.html)

**Videos:**
- [Docker in 100 Seconds - Fireship](https://www.youtube.com/watch?v=Gjnup-PuquQ)
- [Docker Tutorial for Beginners - TechWorld with Nana](https://www.youtube.com/watch?v=3c-iBn73dDE)
- [AWS ECS Tutorial - Stephane Maarek](https://www.youtube.com/watch?v=esISkPlnxL0)
- [Containers on AWS Overview](https://www.youtube.com/watch?v=AYAh6YDXuho)

---

## 5. Databases & Storage — RDS, Redis, S3, EFS

### 🧠 The Concept

Applications need to store two types of data:

1. **Structured data** (users, orders, settings) → **Databases**
2. **Unstructured data** (files, images, videos) → **Object Storage**

AWS provides managed services so you don't have to install/maintain database software:
- **RDS** = Managed PostgreSQL, MySQL, etc.
- **ElastiCache** = Managed Redis (in-memory cache)
- **S3** = Managed object storage (files)
- **EFS** = Managed network file system

### 🎯 Mental Model

Think of it like **storage in your house**:
- **RDS (Relational Database)** = Filing cabinet with labeled folders (structured, organized)
- **ElastiCache (Redis)** = Sticky notes on your desk (quick access to frequently used info)
- **S3 (Object Storage)** = Storage unit warehouse (cheap, unlimited, retrieves anything by key)
- **EFS (File System)** = Shared drive everyone can mount (multiple computers access same files)

### 📂 In This Codebase

#### RDS PostgreSQL
[modules/rds_postgres/main.tf](../modules/rds_postgres/main.tf) lines 12-34:

```hcl
resource "aws_db_instance" "postgres" {
  identifier     = "${var.project_name}-${var.environment}-postgres"
  engine         = "postgres"
  engine_version = "18"
  instance_class = var.db_instance_class  # e.g., "db.t3.micro"
  
  allocated_storage     = 20  # GB
  max_allocated_storage = 100 # Auto-scales up to 100 GB
  
  db_name  = var.db_name
  username = var.db_username
  password = var.db_password  # From Terraform variables (sensitive)
  
  db_subnet_group_name   = aws_db_subnet_group.main.name
  vpc_security_group_ids = [aws_security_group.rds_sg.id]
  
  publicly_accessible = false  # Only accessible from within VPC
  
  backup_retention_period = 7  # Keep backups for 7 days
  deletion_protection     = true  # Prevent accidental deletion
  skip_final_snapshot     = false
  
  storage_encrypted = true  # Encrypt data at rest
}
```

**Why managed RDS?**
- ✅ Automatic backups
- ✅ Automatic patching/updates
- ✅ Multi-AZ failover (for production)
- ✅ Point-in-time recovery
- ❌ You give up SSH access to the database server

**Used for:** User accounts, companies, spaces, bookings, authentication sessions

#### ElastiCache Redis
[environments/dev/main.tf](../environments/dev/main.tf) lines 84-97:

```hcl
resource "aws_elasticache_replication_group" "redis" {
  replication_group_id       = "kuno-main-redis"
  replication_group_description = "Redis cluster for Kuno Main"
  engine                     = "redis"
  engine_version             = "7.0"
  node_type                  = "cache.t2.micro"
  num_cache_clusters         = 1  # Single node (dev)
  
  at_rest_encryption_enabled = true
  transit_encryption_enabled = true
  transit_encryption_mode    = "required"
  auth_token                 = random_password.redis_auth_token.result
  
  subnet_group_name  = aws_elasticache_subnet_group.redis.name
  security_group_ids = [aws_security_group.redis_sg.id]
}
```

**Used for:** 
- Session storage
- Rate limiting
- Job queues (BullMQ)
- Caching frequently accessed data

**Why Redis?**
- Sub-millisecond latency
- In-memory (10-100x faster than disk)
- Supports complex data structures (lists, sets, sorted sets)

#### S3 — Multiple Use Cases
This project uses S3 for **four different purposes**:

**1. Static Website Hosting**
[modules/static_site/main.tf](../modules/static_site/main.tf) lines 1-16:

```hcl
resource "aws_s3_bucket" "site" {
  bucket = var.bucket_name  # e.g., "dev-app.kuno-ai.com"
}

resource "aws_s3_bucket_versioning" "site" {
  bucket = aws_s3_bucket.site.id
  
  versioning_configuration {
    status = "Enabled"  # Keep old versions of files
  }
}
```

**Used for:** Hosting web and portal SPAs (HTML, CSS, JavaScript)

**2. User Uploads**
[environments/dev/s3.tf](../environments/dev/s3.tf) lines 1-86:

```hcl
resource "aws_s3_bucket" "uploads" {
  bucket = "kuno-main-uploads"
}

# Allow public read on specific prefixes
resource "aws_s3_bucket_policy" "uploads" {
  bucket = aws_s3_bucket.uploads.id
  
  policy = jsonencode({
    Statement = [
      {
        Sid    = "PublicReadForAvatars"
        Effect = "Allow"
        Principal = "*"
        Action = "s3:GetObject"
        Resource = [
          "${aws_s3_bucket.uploads.arn}/public/*",
          "${aws_s3_bucket.uploads.arn}/avatars/*",
          "${aws_s3_bucket.uploads.arn}/users/*",
        ]
      }
    ]
  })
}
```

**Used for:** User avatars, company logos, attachment files

**3. Terraform State**
[environments/dev/backend.tf](../environments/dev/backend.tf) lines 1-9:

```hcl
terraform {
  backend "s3" {
    bucket         = "kuno-main-tfstate-e90cb155"
    key            = "dev/terraform.tfstate"
    region         = "eu-west-3"
    encrypt        = true
    dynamodb_table = "kuno-main-tfstate-locks"
  }
}
```

**Used for:** Storing Terraform state (current infrastructure configuration)

**4. Logs**
[environments/dev/s3.tf](../environments/dev/s3.tf) lines 88-96:

```hcl
resource "aws_s3_bucket" "logs" {
  bucket = "kuno-main-logs"
}

resource "aws_s3_bucket_public_access_block" "logs" {
  bucket = aws_s3_bucket.logs.id
  
  block_public_acls       = true
  block_public_policy     = true
  ignore_public_acls      = true
  restrict_public_buckets = true
}
```

**Used for:** CloudFront access logs, ALB logs (if enabled)

#### EFS — Persistent Container Storage
[modules/qdrant_cluster/main.tf](../modules/qdrant_cluster/main.tf) lines 1-25:

```hcl
resource "aws_efs_file_system" "qdrant_data" {
  creation_token = "${var.project_name}-qdrant-efs"
  encrypted      = true
  
  lifecycle_policy {
    transition_to_ia = "AFTER_30_DAYS"  # Move to cheaper storage after 30 days
  }
}

# Mount targets in each subnet
resource "aws_efs_mount_target" "qdrant_data" {
  count           = length(var.private_subnet_ids)
  file_system_id  = aws_efs_file_system.qdrant_data.id
  subnet_id       = var.private_subnet_ids[count.index]
  security_groups = [aws_security_group.efs_sg.id]
}
```

**Why EFS for Qdrant?**
- Qdrant stores vector embeddings (large files)
- ECS containers are ephemeral (restart = data loss)
- EFS provides persistent storage across container restarts
- Multiple containers can mount the same EFS volume

**Usage in task definition:**
[modules/qdrant_cluster/main.tf](../modules/qdrant_cluster/main.tf) lines 95-108:

```hcl
volume {
  name = "qdrant-storage"
  
  efs_volume_configuration {
    file_system_id = aws_efs_file_system.qdrant_data.id
    root_directory = "/"
    transit_encryption = "ENABLED"
  }
}

# Mount in container
mountPoints = [{
  sourceVolume  = "qdrant-storage"
  containerPath = "/qdrant/storage"
  readOnly      = false
}]
```

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **RDS** | Relational Database Service — managed PostgreSQL, MySQL, etc. |
| **ElastiCache** | Managed Redis/Memcached |
| **S3** | Simple Storage Service — object storage for files |
| **EFS** | Elastic File System — network file system (like NFS) |
| **Bucket** | Container for objects in S3 |
| **Object** | File stored in S3 (max 5 TB per object) |
| **Multi-AZ** | Database replicated across multiple data centers |
| **Snapshot** | Point-in-time backup of a database or volume |
| **Versioning** | Keep multiple versions of S3 objects |

### 📖 Further Learning

**Blog Posts:**
- [When to Use Which Database - AWS](https://aws.amazon.com/getting-started/decision-guides/databases-on-aws-how-to-choose/)
- [S3 Best Practices](https://docs.aws.amazon.com/AmazonS3/latest/userguide/security-best-practices.html)
- [Redis Use Cases](https://redis.io/docs/manual/patterns/)
- [RDS vs Self-Managed Database](https://aws.amazon.com/rds/resources/comparing-rds-vs-ec2/)

**Videos:**
- [Database Types Explained in 10 Minutes - Fireship](https://www.youtube.com/watch?v=W2Z7fbCLSTw)
- [AWS S3 Tutorial - TechWorld with Nana](https://www.youtube.com/watch?v=77lMCiiMilo)
- [Redis Crash Course - Web Dev Simplified](https://www.youtube.com/watch?v=jgpVdJB2sKQ)
- [AWS RDS Deep Dive](https://www.youtube.com/watch?v=yjH10T3Migg)

---

## 6. Infrastructure as Code — Terraform Fundamentals

### 🧠 The Concept

**Infrastructure as Code (IaC)** means managing infrastructure using config files instead of clicking through web consoles. Terraform is the most popular IaC tool — it works with AWS, Google Cloud, Azure, and 3,000+ other providers.

**Benefits:**
- ✅ **Reproducible** — rebuild entire infrastructure from code
- ✅ **Version controlled** — track changes with Git
- ✅ **Documented** — code IS the documentation
- ✅ **Testable** — preview changes before applying
- ✅ **Collaborative** — team can review changes

### 🎯 Mental Model

Think of Terraform like **LEGO instructions**:
- **Traditional approach** = Free-building (hard to remember or replicate)
- **Terraform** = Step-by-step instructions (anyone can rebuild the exact same structure)

### 📂 In This Codebase

#### Core Terraform Files
Every environment has these files:

| File | Purpose |
|---|---|
| [backend.tf](../environments/dev/backend.tf) | Where Terraform stores state (S3 + DynamoDB) |
| [main.tf](../environments/dev/main.tf) | Main infrastructure definitions |
| [variables.tf](../environments/dev/variables.tf) | Input variables (customizable values) |
| [outputs.tf](../environments/dev/outputs.tf) | Output values (e.g., URLs, IDs) |
| [secrets.tf](../environments/dev/secrets.tf) | Secret management (SSM parameters) |
| [s3.tf](../environments/dev/s3.tf) | S3 bucket definitions |
| [billing.tf](../environments/dev/billing.tf) | Cost alerts and budgets |

#### Variables — Customizable Inputs
[environments/dev/variables.tf](../environments/dev/variables.tf) lines 1-40:

```hcl
variable "project_name" {
  description = "Project name prefix"
  type        = string
  default     = "kuno-main"
}

variable "environment" {
  description = "Environment name"
  type        = string
  default     = "dev"
}

variable "vpc_cidr" {
  description = "CIDR block for VPC"
  type        = string
  default     = "10.0.0.0/16"
}

variable "task_cpu_backend" {
  description = "CPU units for backend task"
  type        = string
  default     = "256"  # 0.25 vCPU
}

variable "db_password" {
  description = "PostgreSQL master password"
  type        = string
  sensitive   = true  # Terraform won't print this in logs
}
```

**How to use variables:**
```hcl
# Reference in code
resource "aws_vpc" "main" {
  cidr_block = var.vpc_cidr
}
```

**How to set variables:**
```bash
# Option 1: terraform.tfvars file (not committed to git)
db_password = "super-secret-password"

# Option 2: Environment variable
export TF_VAR_db_password="super-secret-password"

# Option 3: Command line
terraform apply -var="db_password=super-secret-password"
```

#### Resources — Create Infrastructure
[environments/dev/main.tf](../environments/dev/main.tf) lines 1-30:

```hcl
# Provider configuration
provider "aws" {
  region = var.region
}

# VPC creation
resource "aws_vpc" "main" {
  cidr_block           = var.vpc_cidr
  enable_dns_hostnames = true
  
  tags = {
    Name        = "${var.project_name}-vpc"
    Environment = var.environment
  }
}

# Security group
resource "aws_security_group" "alb_sg" {
  name        = "${var.project_name}-alb-sg"
  description = "Security group for Application Load Balancer"
  vpc_id      = aws_vpc.main.id
  
  ingress {
    from_port   = 443
    to_port     = 443
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }
}
```

**Resource syntax:**
```hcl
resource "TYPE" "NAME" {
  # configuration
}

# Reference as: TYPE.NAME.ATTRIBUTE
# Example: aws_vpc.main.id
```

#### Data Sources — Query Existing Resources
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 172-174:

```hcl
data "aws_route53_zone" "main" {
  name = var.domain_name  # "kuno-ai.com"
}

# Use: data.aws_route53_zone.main.zone_id
```

**Data sources** query resources that already exist (not created by Terraform):
- Existing Route53 zone
- Existing ECR repository
- AWS account ID
- Current AWS region

#### Outputs — Export Values
[environments/dev/outputs.tf](../environments/dev/outputs.tf) lines 1-30:

```hcl
output "backend_api_url" {
  description = "Backend API URL"
  value       = "https://${var.backend_domain}"
}

output "postgres_endpoint" {
  description = "RDS PostgreSQL endpoint"
  value       = aws_db_instance.postgres.endpoint
}

output "redis_endpoint" {
  description = "Redis endpoint"
  value       = aws_elasticache_replication_group.redis.primary_endpoint_address
}

output "web_cloudfront_url" {
  description = "Web app CloudFront URL"
  value       = module.web_app.cloudfront_domain_name
}
```

**How to use outputs:**
```bash
# View all outputs
terraform output

# Get specific output
terraform output -raw backend_api_url

# Use in scripts
API_URL=$(terraform output -raw backend_api_url)
```

The [deploy-frontend.sh](../cli/deploy-frontend.sh) script uses outputs:
```bash
API_URL=$(terraform -chdir=environments/dev output -raw backend_api_url)
S3_BUCKET=$(terraform -chdir=environments/dev output -raw web_bucket_name)
```

#### Locals — Computed Values
[environments/dev/secrets.tf](../environments/dev/secrets.tf) lines 90-115:

```hcl
locals {
  # List of all secret keys
  app_secret_keys = [
    "BETTER_AUTH_SECRET",
    "DATABASE_URL",
    "REDIS_URL",
    "RESEND_API_KEY",
    "SENTRY_DSN",
    "GOOGLE_CLIENT_ID",
    "GOOGLE_CLIENT_SECRET",
    # ... more keys
  ]
  
  # Compute DATABASE_URL from other variables
  database_url = "postgresql://${var.db_username}:${urlencode(var.db_password)}@${aws_db_instance.postgres.endpoint}/${var.db_name}"
}
```

**Locals vs Variables:**
- **Variables** = Inputs (set by user)
- **Locals** = Computed from other values (like functions)

#### Terraform Workflow
[kc](../kc) wraps common Terraform commands:

```bash
# 1. Initialize (download providers, modules)
./kc init
# Runs: terraform -chdir=environments/dev init

# 2. Validate syntax
./kc validate
# Runs: terraform -chdir=environments/dev validate

# 3. Preview changes
./kc plan
# Runs: terraform -chdir=environments/dev plan

# 4. Apply changes
./kc apply
# Runs: terraform -chdir=environments/dev apply

# 5. View outputs
./kc output
# Runs: terraform -chdir=environments/dev output
```

**What happens when you run `terraform apply`?**
1. Terraform reads your `.tf` files
2. Reads current state from S3 (`terraform.tfstate`)
3. Compares desired state (code) with actual state (AWS)
4. Shows you what will change (create, update, delete)
5. Asks for confirmation
6. Makes API calls to AWS to apply changes
7. Updates state file

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **Terraform** | Infrastructure as Code tool (works with AWS, GCP, Azure, etc.) |
| **Provider** | Plugin that talks to an API (e.g., AWS provider) |
| **Resource** | Infrastructure component you want to create (VPC, EC2, S3, etc.) |
| **Data Source** | Query existing resources (not created by Terraform) |
| **Variable** | Input parameter (customizable value) |
| **Output** | Exported value (like a function return value) |
| **Local** | Computed value (derived from other values) |
| **State** | Terraform's record of current infrastructure |
| **Plan** | Preview of changes before applying |
| **Apply** | Execute changes to infrastructure |

### 📖 Further Learning

**Blog Posts:**
- [Terraform Tutorial for Beginners - HashiCorp Learn](https://developer.hashicorp.com/terraform/tutorials/aws-get-started)
- [How Terraform Works - Yevgeniy Brikman](https://blog.gruntwork.io/how-terraform-works-a-visual-intro-to-the-fundamental-concepts-93c5db5ea6d9)
- [Terraform Best Practices](https://www.terraform-best-practices.com/)
- [Infrastructure as Code Explained](https://www.hashicorp.com/resources/what-is-infrastructure-as-code)

**Videos:**
- [Terraform Explained in 15 Minutes - TechWorld with Nana](https://www.youtube.com/watch?v=l5k1ai_GBDE)
- [Terraform Course - Beginner to Advanced - freeCodeCamp](https://www.youtube.com/watch?v=SLB_c_ayRMo)
- [Infrastructure as Code in 100 Seconds - Fireship](https://www.youtube.com/watch?v=POPP2WTJ8es)
- [Terraform State Explained](https://www.youtube.com/watch?v=7xngnjfIlK4)

---

## 7. Terraform Advanced — Modules, State Management, Multi-Provider

### 🧠 The Concept

As Terraform code grows, you need **modules** (reusable components) and **state management** (tracking infrastructure across teams).

**Modules** = Functions in programming — write once, reuse many times
**State** = Database of what infrastructure currently exists
**State Locking** = Prevents two people from running `terraform apply` simultaneously

### 🎯 Mental Model

Think of modules like **blueprints**:
- **Without modules** = Redraw the entire house plan for every house
- **With modules** = Use standard blueprints (kitchen, bedroom, bathroom) and assemble them

Think of state like **version control for infrastructure**:
- **State file** = Current state of your infrastructure (like a Git commit)
- **State locking** = Like Git preventing two people from pushing simultaneously

### 📂 In This Codebase

#### Module Structure
This project has **6 reusable modules**:

```
modules/
├── vpc/              # Network infrastructure
├── ecs_service/      # Web service (ALB + ECS + logs)
├── rds_postgres/     # PostgreSQL database
├── qdrant_cluster/   # Vector database on ECS + EFS
├── static_site/      # S3 + CloudFront + DNS
└── bedrock/          # AWS Bedrock IAM role
```

Each module has the same structure:
```
module_name/
├── main.tf       # Resource definitions
├── variables.tf  # Input variables
└── outputs.tf    # Return values
```

#### Module Example: VPC
[modules/vpc/variables.tf](../modules/vpc/variables.tf):

```hcl
variable "project_name" {
  description = "Project name prefix"
  type        = string
}

variable "vpc_cidr" {
  description = "CIDR block for VPC"
  type        = string
}

variable "public_subnet_cidrs" {
  description = "CIDR blocks for public subnets"
  type        = list(string)
}
```

[modules/vpc/outputs.tf](../modules/vpc/outputs.tf):

```hcl
output "vpc_id" {
  description = "VPC ID"
  value       = aws_vpc.main.id
}

output "public_subnet_ids" {
  description = "Public subnet IDs"
  value       = [
    aws_subnet.public_subnet_1.id,
    aws_subnet.public_subnet_2.id,
  ]
}
```

#### Using Modules
[environments/dev/main.tf](../environments/dev/main.tf) lines 35-46:

```hcl
module "vpc" {
  source = "../../modules/vpc"  # Path to module
  
  # Input variables
  project_name         = var.project_name
  vpc_cidr             = var.vpc_cidr
  public_subnet_cidrs  = var.public_subnet_cidrs
  private_subnet_cidrs = var.private_subnet_cidrs
  region               = var.region
  enable_nat_gateway   = var.enable_nat_gateway
}

# Access module outputs
module "kuno_backend_service" {
  source = "../../modules/ecs_service"
  
  vpc_id            = module.vpc.vpc_id           # From VPC module
  public_subnet_ids = module.vpc.public_subnet_ids
  private_subnet_ids = module.vpc.private_subnet_ids
}
```

**Why modules?**
- ✅ **DRY (Don't Repeat Yourself)** — VPC code written once, used in dev and prod
- ✅ **Consistency** — Every ECS service configured the same way
- ✅ **Easier updates** — Change module once, affects all uses
- ✅ **Testable** — Test module in isolation

#### State Management
[environments/dev/backend.tf](../environments/dev/backend.tf):

```hcl
terraform {
  backend "s3" {
    bucket         = "kuno-main-tfstate-e90cb155"
    key            = "dev/terraform.tfstate"
    region         = "eu-west-3"
    encrypt        = true
    dynamodb_table = "kuno-main-tfstate-locks"
  }
}
```

**What this does:**
- State file stored in **S3** (not locally)
- Encrypted at rest
- DynamoDB table provides **state locking**
- Separate state per environment (`dev/terraform.tfstate`, `prod/terraform.tfstate`)

**Why remote state?**
- ✅ **Team collaboration** — Everyone sees the same state
- ✅ **Backup** — S3 has 11 nines of durability
- ✅ **Locking** — Prevents simultaneous applies

**State locking workflow:**
```
Developer A runs: terraform apply
  → Locks DynamoDB record
  → Makes changes
  → Releases lock

Developer B runs: terraform apply (while A is still running)
  → Sees lock
  → Waits or exits with error
```

#### Multi-Provider Configuration
[environments/dev/main.tf](../environments/dev/main.tf) lines 1-9:

```hcl
provider "aws" {
  region = var.region  # eu-west-3 for most resources
}

provider "aws" {
  alias  = "us_east_1"
  region = "us-east-1"  # Required for CloudFront certificates
}
```

**Why two providers?**
- CloudFront is a **global service** (not regional)
- CloudFront SSL certificates **must** be created in `us-east-1`
- All other resources use `eu-west-3`

**Usage:**
[modules/static_site/main.tf](../modules/static_site/main.tf) lines 110-125:

```hcl
resource "aws_acm_certificate" "cert_us_east_1" {
  provider          = aws.us_east_1  # Use us-east-1 provider
  domain_name       = var.domain
  validation_method = "DNS"
  
  lifecycle {
    create_before_destroy = true
  }
}

resource "aws_cloudfront_distribution" "cdn" {
  # CloudFront uses us-east-1 certificate
  viewer_certificate {
    acm_certificate_arn = aws_acm_certificate.cert_us_east_1.arn
    ssl_support_method  = "sni-only"
  }
}
```

#### Meta-Arguments
Terraform provides special keywords for advanced control:

**1. `count` — Create multiple similar resources**
[modules/vpc/main.tf](../modules/vpc/main.tf) lines 68-78:

```hcl
resource "aws_nat_gateway" "main" {
  count = var.enable_nat_gateway ? 1 : 0  # Conditional creation
  
  allocation_id = aws_eip.nat[count.index].id
  subnet_id     = aws_subnet.public_subnet_1.id
}
```

If `enable_nat_gateway = false`, NAT Gateway is not created (saves $32/month).

**2. `for_each` — Create resources from a map or set**
[environments/dev/secrets.tf](../environments/dev/secrets.tf) lines 117-127:

```hcl
resource "aws_ssm_parameter" "app_secrets" {
  for_each = toset(local.app_secret_keys)
  
  name  = "/kuno-main/${var.environment}/${each.key}"
  type  = "SecureString"
  value = lookup(var.application_secrets, each.key, "placeholder")
}
```

Creates one SSM parameter for each key in the list.

**3. `depends_on` — Explicit ordering**
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 155-165:

```hcl
resource "aws_lb_listener" "https" {
  load_balancer_arn = aws_lb.main.arn
  port              = "443"
  protocol          = "HTTPS"
  certificate_arn   = var.certificate_arn
  
  depends_on = [aws_lb_target_group.main]
}
```

Ensures target group is created before the listener.

**4. `dynamic` — Generate nested blocks**
[modules/vpc/main.tf](../modules/vpc/main.tf) lines 90-110:

```hcl
resource "aws_route_table" "private" {
  vpc_id = aws_vpc.main.id
  
  # Only add NAT Gateway route if it exists
  dynamic "route" {
    for_each = var.enable_nat_gateway ? [1] : []
    content {
      cidr_block     = "0.0.0.0/0"
      nat_gateway_id = aws_nat_gateway.main[0].id
    }
  }
}
```

**5. `lifecycle` — Control resource behavior**
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 115-119:

```hcl
resource "aws_acm_certificate" "cert" {
  domain_name = var.domain
  
  lifecycle {
    create_before_destroy = true  # Create new cert before deleting old
  }
}
```

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **Module** | Reusable Terraform code (like a function) |
| **State** | Terraform's record of current infrastructure |
| **Remote State** | State file stored in S3/cloud (not locally) |
| **State Locking** | Prevents simultaneous Terraform runs |
| **Provider** | Plugin for a specific cloud/service |
| **Provider Alias** | Multiple configurations of same provider |
| **Meta-argument** | Special Terraform keywords (`count`, `for_each`, etc.) |
| **Lifecycle** | Rules for resource creation/deletion |

### 📖 Further Learning

**Blog Posts:**
- [Terraform Modules Tutorial - HashiCorp](https://developer.hashicorp.com/terraform/tutorials/modules/module)
- [Terraform State Deep Dive](https://blog.gruntwork.io/how-to-manage-terraform-state-28f5697e68fa)
- [When to Use count vs for_each](https://www.terraform.io/language/meta-arguments/count#when-to-use-for_each-instead-of-count)
- [Terraform Best Practices - Google Cloud](https://cloud.google.com/docs/terraform/best-practices-for-terraform)

**Videos:**
- [Terraform Modules Explained - TechWorld with Nana](https://www.youtube.com/watch?v=0wEiCubx3Q8)
- [Terraform State Management](https://www.youtube.com/watch?v=7xngnjfIlK4)
- [Advanced Terraform - Pluralsight](https://www.youtube.com/watch?v=wgzgVm7Sqlk)

---

## 8. Secrets & IAM Security — SSM, Roles, Least Privilege

### 🧠 The Concept

**Security principles:**
1. **Never hardcode secrets** in code (API keys, passwords)
2. **Encrypt secrets at rest** (stored data) and **in transit** (network)
3. **Least privilege** — give minimal permissions needed
4. **Separation of concerns** — different roles for different tasks

**AWS IAM (Identity and Access Management)** controls **who** can do **what** with **which resources**.

### 🎯 Mental Model

Think of IAM like **building security**:
- **IAM User** = Person with a badge
- **IAM Role** = Job title (manager, security guard, janitor)
- **IAM Policy** = List of allowed actions ("can enter server room", "can't access CEO office")
- **Principle of Least Privilege** = Give each person only the keys they need (janitor doesn't need keys to every room)

### 📂 In This Codebase

#### Secrets Management with SSM Parameter Store
[environments/dev/secrets.tf](../environments/dev/secrets.tf) lines 1-50:

**Step 1: Define secret keys**
```hcl
variable "application_secrets" {
  description = "Application secrets"
  type        = map(string)
  sensitive   = true
  default = {
    BETTER_AUTH_SECRET    = "placeholder"
    DATABASE_URL          = ""  # Computed below
    RESEND_API_KEY        = "placeholder"
    SENTRY_DSN            = "placeholder"
    GOOGLE_CLIENT_ID      = "placeholder"
    GOOGLE_CLIENT_SECRET  = "placeholder"
    # ... more secrets
  }
}

locals {
  app_secret_keys = [
    "BETTER_AUTH_SECRET",
    "DATABASE_URL",
    "RESEND_API_KEY",
    "SENTRY_DSN",
    "GOOGLE_CLIENT_ID",
    "GOOGLE_CLIENT_SECRET",
    # ... more keys
  ]
}
```

**Step 2: Create SSM parameters**
```hcl
resource "aws_ssm_parameter" "app_secrets" {
  for_each = toset(local.app_secret_keys)
  
  name  = "/kuno-main/${var.environment}/${each.key}"
  type  = "SecureString"  # Encrypted with AWS KMS
  value = lookup(var.application_secrets, each.key, "placeholder")
  
  overwrite = true
}
```

**Step 3: Reference in ECS task definition**
[environments/dev/main.tf](../environments/dev/main.tf) lines 175-192:

```hcl
module "kuno_backend_service" {
  # ... other config ...
  
  secrets = merge(
    {
      for k in local.app_secret_keys :
      k => aws_ssm_parameter.app_secrets[k].arn
    },
    {
      DATABASE_URL = aws_ssm_parameter.database_url.arn
      REDIS_URL    = aws_ssm_parameter.redis_url.arn
    }
  )
}
```

**What happens at runtime?**
1. ECS task starts
2. ECS pulls SSM parameters using the **execution role**
3. SSM decrypts values using KMS
4. ECS injects secrets as environment variables
5. **Secrets never appear in task definition** (only ARNs)

#### Syncing Secrets from .env Files
[cli/sync-secrets.sh](../cli/sync-secrets.sh) lines 10-40:

```bash
# Secrets that should exist in .env.development
EXPECTED_SECRETS=(
  "BETTER_AUTH_SECRET"
  "RESEND_API_KEY"
  "SENTRY_DSN"
  "GOOGLE_CLIENT_ID"
  "GOOGLE_CLIENT_SECRET"
  # ... more
)

# Read from .env.development
ENV_FILE="../kuno-backend/.env.development"

for key in "${EXPECTED_SECRETS[@]}"; do
  value=$(grep "^${key}=" "$ENV_FILE" | cut -d '=' -f2-)
  
  if [ -n "$value" ]; then
    aws ssm put-parameter \
      --name "/kuno-main/dev/${key}" \
      --type "SecureString" \
      --value "$value" \
      --overwrite
  fi
done
```

**Usage:**
```bash
./kc sync secrets  # Dev environment
./kc-prod sync secrets  # Prod environment
```

#### IAM Roles for ECS
There are **two roles** for each ECS task:

**1. Execution Role** — Used by ECS agent
[environments/dev/main.tf](../environments/dev/main.tf) lines 50-75:

```hcl
resource "aws_iam_role" "ecs_execution_role" {
  name = "${var.project_name}-ecs-execution-role"
  
  # WHO can assume this role?
  assume_role_policy = jsonencode({
    Version = "2012-10-17"
    Statement = [{
      Action = "sts:AssumeRole"
      Effect = "Allow"
      Principal = {
        Service = "ecs-tasks.amazonaws.com"
      }
    }]
  })
}

# Attach AWS-managed policy (pull ECR images, write CloudWatch logs)
resource "aws_iam_role_policy_attachment" "ecs_execution_role_policy" {
  role       = aws_iam_role.ecs_execution_role.name
  policy_arn = "arn:aws:iam::aws:policy/service-role/AmazonECSTaskExecutionRolePolicy"
}

# Add SSM permissions
resource "aws_iam_role_policy" "ecs_execution_ssm" {
  role = aws_iam_role.ecs_execution_role.id
  
  policy = jsonencode({
    Version = "2012-10-17"
    Statement = [{
      Effect = "Allow"
      Action = [
        "ssm:GetParameter",
        "ssm:GetParameters"
      ]
      Resource = "arn:aws:ssm:${var.region}:*:parameter/kuno-main/${var.environment}/*"
    }]
  })
}
```

**Execution role can:**
- Pull Docker images from ECR
- Get secrets from SSM Parameter Store
- Write logs to CloudWatch

**2. Task Role** — Used by the application
[environments/dev/main.tf](../environments/dev/main.tf) lines 77-130:

```hcl
resource "aws_iam_role" "ecs_task_role" {
  name = "${var.project_name}-ecs-task-role"
  
  assume_role_policy = jsonencode({
    Version = "2012-10-17"
    Statement = [{
      Action = "sts:AssumeRole"
      Effect = "Allow"
      Principal = {
        Service = "ecs-tasks.amazonaws.com"
      }
    }]
  })
}

resource "aws_iam_role_policy" "ecs_task_s3" {
  role = aws_iam_role.ecs_task_role.id
  
  policy = jsonencode({
    Version = "2012-10-17"
    Statement = [
      {
        Effect = "Allow"
        Action = [
          "s3:PutObject",
          "s3:GetObject",
          "s3:DeleteObject"
        ]
        Resource = "arn:aws:s3:::kuno-main-uploads/*"
      },
      {
        Effect = "Allow"
        Action = ["s3:ListBucket"]
        Resource = "arn:aws:s3:::kuno-main-uploads"
      },
      {
        Effect = "Allow"
        Action = ["bedrock:InvokeModel"]
        Resource = "arn:aws:bedrock:eu-west-3::foundation-model/mistral.mistral-7b-instruct-v0:2"
      }
    ]
  })
}
```

**Task role can:**
- Upload/download files from S3 uploads bucket
- Invoke AWS Bedrock AI models
- Execute ECS Exec commands (SSH-like access)

#### Developer IAM Policies — Three Tiers
This project has **three developer permission levels**:

**Tier 1: Basic Developer**
[iam-policies/developer-policy.json](../iam-policies/developer-policy.json):

```json
{
  "Version": "2012-10-17",
  "Statement": [
    {
      "Effect": "Allow",
      "Action": [
        "bedrock:InvokeModel"
      ],
      "Resource": "arn:aws:bedrock:eu-west-3::foundation-model/mistral.mistral-7b-instruct-v0:2"
    },
    {
      "Effect": "Allow",
      "Action": [
        "ecs:UpdateService",
        "ecs:DescribeServices",
        "ecs:ListTasks"
      ],
      "Resource": "*"
    }
  ]
}
```

**Can:**
- Test Bedrock AI locally
- Start/stop/restart ECS services
- View ECS service status

**Cannot:**
- View logs
- Deploy code
- Access databases

**Tier 2: Log Developer**
[iam-policies/log-dev-policy.json](../iam-policies/log-dev-policy.json):

```json
{
  "Statement": [
    {
      "Effect": "Allow",
      "Action": [
        "logs:DescribeLogGroups",
        "logs:DescribeLogStreams",
        "logs:GetLogEvents",
        "logs:FilterLogEvents",
        "logs:StartLiveTail",
        "logs:StopLiveTail"
      ],
      "Resource": "*"
    },
    {
      "Effect": "Allow",
      "Action": [
        "ecr:*"
      ],
      "Resource": "*"
    },
    {
      "Effect": "Allow",
      "Action": [
        "ecs:ExecuteCommand"
      ],
      "Resource": "*"
    }
  ]
}
```

**Can (in addition to basic):**
- View CloudWatch logs
- Push Docker images to ECR
- Deploy backend/rag1 services
- SSH into containers (ECS Exec)

**Tier 3: Cloud Developer**
[iam-policies/cloud-dev-policy.json](../iam-policies/cloud-dev-policy.json):

```json
{
  "Statement": [
    {
      "Effect": "Allow",
      "Action": [
        "s3:*"
      ],
      "Resource": [
        "arn:aws:s3:::kuno-main-*",
        "arn:aws:s3:::kuno-main-*/*"
      ]
    },
    {
      "Effect": "Allow",
      "Action": [
        "cloudfront:CreateInvalidation",
        "cloudfront:GetInvalidation"
      ],
      "Resource": "*"
    },
    {
      "Effect": "Allow",
      "Action": [
        "ssm:GetParameter",
        "ssm:GetParameters"
      ],
      "Resource": "*"
    },
    {
      "Effect": "Allow",
      "Action": [
        "ce:GetCostAndUsage"
      ],
      "Resource": "*"
    }
  ]
}
```

**Can (in addition to log):**
- Deploy frontends to S3
- Invalidate CloudFront cache
- View AWS costs
- Read SSM parameters
- View Terraform state

#### Managing Developers
[cli/setup-developer.sh](../cli/setup-developer.sh) creates IAM users:

```bash
./kc-admin add-dev alice alice@kuno.live         # Basic
./kc-admin add-log-dev bob bob@kuno.live         # Log
./kc-admin add-cloud-dev charlie charlie@kuno.live  # Cloud
```

**What it does:**
1. Creates IAM user
2. Adds to appropriate IAM group (`kuno-developers`, `kuno-log-developers`, or `kuno-cloud-developers`)
3. Creates access key (outputs `AWS_ACCESS_KEY_ID` and `AWS_SECRET_ACCESS_KEY`)
4. User configures AWS CLI with credentials

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **IAM** | Identity and Access Management — AWS's permission system |
| **IAM User** | Person or service account with permanent credentials |
| **IAM Role** | Set of permissions that can be assumed temporarily |
| **IAM Policy** | JSON document defining allowed/denied actions |
| **Principal** | Entity that can perform actions (user, role, service) |
| **SSM Parameter Store** | Secure storage for configuration and secrets |
| **SecureString** | Encrypted SSM parameter (uses AWS KMS) |
| **Execution Role** | Role used by ECS to start the container |
| **Task Role** | Role used by the application code inside the container |
| **Least Privilege** | Give minimal permissions needed (security best practice) |
| **KMS** | Key Management Service — encryption key management |

### 📖 Further Learning

**Blog Posts:**
- [AWS IAM Tutorial - AWS Official](https://docs.aws.amazon.com/IAM/latest/UserGuide/introduction.html)
- [IAM Roles vs Users vs Groups](https://stackoverflow.com/questions/46199680/difference-between-iam-role-and-iam-user-in-aws)
- [AWS Secrets Manager vs SSM Parameter Store](https://tutorialsdojo.com/aws-secrets-manager-vs-systems-manager-parameter-store/)
- [Principle of Least Privilege](https://docs.aws.amazon.com/IAM/latest/UserGuide/best-practices.html#grant-least-privilege)

**Videos:**
- [AWS IAM Explained - TechWorld with Nana](https://www.youtube.com/watch?v=ExjW3HCFVGA)
- [IAM Roles vs Users - Stephane Maarek](https://www.youtube.com/watch?v=XMi5fXL2Hes)
- [AWS Security Best Practices - freeCodeCamp](https://www.youtube.com/watch?v=Y4XRMH-qNHk)
- [Managing Secrets in AWS](https://www.youtube.com/watch?v=BoMVs0SQEqA)

---

## 9. CDN, TLS & Frontend Delivery — CloudFront, ACM

### 🧠 The Concept

**Static sites** (HTML, CSS, JavaScript) don't need a server to run — browsers execute the code. But you still need to:
1. **Store files** somewhere (S3)
2. **Deliver files fast** globally (CloudFront CDN)
3. **Encrypt traffic** (HTTPS with SSL certificates)
4. **Handle routing** (all URLs serve `index.html` for client-side routing)

**CDN (Content Delivery Network)** = Global network of servers that cache your content close to users.

### 🎯 Mental Model

Think of a CDN like **Amazon distribution centers**:
- **Without CDN** = All packages ship from one warehouse in Paris (slow for users in Tokyo)
- **With CDN** = Amazon copies products to warehouses worldwide (fast delivery everywhere)

Think of HTTPS like **tamper-proof packaging**:
- **HTTP** = Postcard (anyone can read it)
- **HTTPS** = Sealed envelope with signature (encrypted, verified sender)

### 📂 In This Codebase

#### Static Site Module
[modules/static_site/main.tf](../modules/static_site/main.tf) orchestrates S3 + CloudFront + DNS + SSL.

**Step 1: S3 Bucket**
```hcl
resource "aws_s3_bucket" "site" {
  bucket = var.bucket_name  # e.g., "dev-app.kuno-ai.com"
}

resource "aws_s3_bucket_versioning" "site" {
  bucket = aws_s3_bucket.site.id
  
  versioning_configuration {
    status = "Enabled"  # Keep old versions (can rollback)
  }
}

resource "aws_s3_bucket_public_access_block" "site" {
  bucket = aws_s3_bucket.site.id
  
  # Block ALL public access
  block_public_acls       = true
  block_public_policy     = true
  ignore_public_acls      = true
  restrict_public_buckets = true
}
```

**Why block public access?**
- Only CloudFront can access the bucket
- Direct S3 URLs like `s3.amazonaws.com/bucket/index.html` are blocked
- Users must go through CloudFront (caching, TLS, custom domain)

**Step 2: SSL Certificate (us-east-1)**
```hcl
resource "aws_acm_certificate" "cert_us_east_1" {
  provider = aws.us_east_1  # CloudFront requires us-east-1
  
  domain_name       = var.domain  # "dev-app.kuno-ai.com"
  validation_method = "DNS"
  
  lifecycle {
    create_before_destroy = true  # No downtime during renewal
  }
}

# Create Route53 DNS records for validation
resource "aws_route53_record" "cert_validation" {
  for_each = {
    for dvo in aws_acm_certificate.cert_us_east_1.domain_validation_options : 
    dvo.domain_name => dvo
  }
  
  zone_id = data.aws_route53_zone.main.zone_id
  name    = each.value.resource_record_name
  type    = each.value.resource_record_type
  records = [each.value.resource_record_value]
  ttl     = 60
}

# Wait for validation to complete
resource "aws_acm_certificate_validation" "cert" {
  provider        = aws.us_east_1
  certificate_arn = aws_acm_certificate.cert_us_east_1.arn
  
  validation_record_fqdns = [
    for record in aws_route53_record.cert_validation : record.fqdn
  ]
}
```

**How DNS validation works:**
1. ACM generates a unique CNAME record
2. Terraform creates that CNAME in Route53
3. ACM checks Route53 for the record
4. If found, ACM issues the certificate

**Step 3: CloudFront Distribution**
[modules/static_site/main.tf](../modules/static_site/main.tf) lines 60-200:

```hcl
resource "aws_cloudfront_distribution" "cdn" {
  enabled             = true
  is_ipv6_enabled     = true
  default_root_object = "index.html"
  price_class         = "PriceClass_100"  # North America + Europe
  
  # Custom domain
  aliases = [var.domain]
  
  # S3 origin
  origin {
    domain_name              = aws_s3_bucket.site.bucket_regional_domain_name
    origin_id                = "S3-${var.bucket_name}"
    origin_access_control_id = aws_cloudfront_origin_access_control.oac.id
  }
  
  # Default cache behavior
  default_cache_behavior {
    target_origin_id       = "S3-${var.bucket_name}"
    viewer_protocol_policy = "redirect-to-https"  # Force HTTPS
    
    allowed_methods = ["GET", "HEAD", "OPTIONS"]
    cached_methods  = ["GET", "HEAD"]
    
    # Use AWS managed cache policy
    cache_policy_id = data.aws_cloudfront_cache_policy.caching_optimized.id
    
    compress = true  # Gzip compression
  }
  
  # SPA routing — serve index.html for all 404s
  custom_error_response {
    error_code         = 403
    response_code      = 200
    response_page_path = "/index.html"
  }
  
  custom_error_response {
    error_code         = 404
    response_code      = 200
    response_page_path = "/index.html"
  }
  
  # SSL certificate
  viewer_certificate {
    acm_certificate_arn      = aws_acm_certificate_validation.cert.certificate_arn
    ssl_support_method       = "sni-only"  # Modern browsers only
    minimum_protocol_version = "TLSv1.2_2021"
  }
  
  restrictions {
    geo_restriction {
      restriction_type = "none"  # Available worldwide
    }
  }
}
```

**What CloudFront does:**
- Caches files globally (~200+ edge locations)
- Serves files with low latency (from nearest location)
- Forces HTTPS (redirects HTTP → HTTPS)
- Compresses files (Gzip)
- Handles SPA routing (404 → index.html)

**Step 4: CloudFront Origin Access Control (OAC)**
```hcl
resource "aws_cloudfront_origin_access_control" "oac" {
  name                              = "${var.bucket_name}-oac"
  origin_access_control_origin_type = "s3"
  signing_behavior                  = "always"
  signing_protocol                  = "sigv4"
}

# Grant CloudFront access to S3
resource "aws_s3_bucket_policy" "site" {
  bucket = aws_s3_bucket.site.id
  
  policy = jsonencode({
    Version = "2012-10-17"
    Statement = [{
      Effect = "Allow"
      Principal = {
        Service = "cloudfront.amazonaws.com"
      }
      Action = "s3:GetObject"
      Resource = "${aws_s3_bucket.site.arn}/*"
      Condition = {
        StringEquals = {
          "AWS:SourceArn" = aws_cloudfront_distribution.cdn.arn
        }
      }
    }]
  })
}
```

**OAC** (Origin Access Control) replaces the legacy OAI (Origin Access Identity):
- CloudFront signs requests to S3 using AWS SigV4
- S3 verifies the signature
- Only CloudFront can access the bucket

**Step 5: Route53 DNS**
```hcl
resource "aws_route53_record" "site" {
  zone_id = data.aws_route53_zone.main.zone_id
  name    = var.domain  # "dev-app.kuno-ai.com"
  type    = "A"
  
  alias {
    name                   = aws_cloudfront_distribution.cdn.domain_name
    zone_id                = aws_cloudfront_distribution.cdn.hosted_zone_id
    evaluate_target_health = false
  }
}
```

**DNS flow:**
1. User types `dev-app.kuno-ai.com` in browser
2. Browser queries Route53
3. Route53 returns CloudFront domain (`d111111abcdef8.cloudfront.net`)
4. Browser connects to nearest CloudFront edge location
5. CloudFront serves cached file or fetches from S3

#### Frontend Deployment Workflow
[cli/deploy-frontend.sh](../cli/deploy-frontend.sh) lines 40-115:

```bash
# Get infrastructure outputs
API_URL=$(terraform -chdir=environments/dev output -raw backend_api_url)
S3_BUCKET=$(terraform -chdir=environments/dev output -raw web_bucket_name)
CF_DISTRIBUTION_ID=$(terraform -chdir=environments/dev output -raw web_cloudfront_id)

# Build frontend
cd ../kuno-web
export VITE_API_BASE_URL="$API_URL"
bun install
bun run build:web

# Upload to S3 with cache headers
aws s3 sync dist/ s3://$S3_BUCKET/ \
  --delete \
  --exclude "*.html" \
  --cache-control "public, max-age=31536000, immutable"

# Upload HTML separately (no caching)
aws s3 cp dist/index.html s3://$S3_BUCKET/index.html \
  --cache-control "no-cache"

# Invalidate CloudFront cache
aws cloudfront create-invalidation \
  --distribution-id $CF_DISTRIBUTION_ID \
  --paths "/*"
```

**Why different cache headers?**

| File Type | Cache-Control | Reason |
|---|---|---|
| Assets (`app.abc123.js`) | `max-age=31536000, immutable` | Filename includes hash; safe to cache forever |
| `index.html` | `no-cache` | Always fetch latest (references new hashed assets) |

#### PostHog Analytics Proxy
[modules/static_site/main.tf](../modules/static_site/main.tf) lines 150-250 (simplified):

```hcl
# Proxy PostHog requests through CloudFront
ordered_cache_behavior {
  path_pattern     = "/e/*"  # Event ingestion
  target_origin_id = local.posthog_ingest_origin_id
  
  allowed_methods = ["GET", "HEAD", "OPTIONS", "PUT", "POST", "PATCH", "DELETE"]
  cached_methods  = ["GET", "HEAD"]
  
  cache_policy_id = data.aws_cloudfront_cache_policy.caching_disabled.id
  
  viewer_protocol_policy = "redirect-to-https"
  compress               = true
}

origin {
  domain_name = "eu.i.posthog.com"
  origin_id   = local.posthog_ingest_origin_id
  
  custom_origin_config {
    http_port              = 80
    https_port             = 443
    origin_protocol_policy = "https-only"
    origin_ssl_protocols   = ["TLSv1.2"]
  }
}
```

**Why proxy PostHog?**
- Ad blockers block `posthog.com` requests
- Requests to `dev-app.kuno-ai.com/e/capture` are NOT blocked
- CloudFront forwards to `eu.i.posthog.com` behind the scenes

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **CDN** | Content Delivery Network — global cache for fast content delivery |
| **CloudFront** | AWS's CDN service |
| **Edge Location** | CDN server close to users (~200+ worldwide) |
| **Origin** | Source of content (S3 bucket, API server, etc.) |
| **Cache** | Temporary copy of content stored at edge location |
| **TTL** | Time To Live — how long to cache before refreshing |
| **Invalidation** | Force CloudFront to delete cached files |
| **SSL/TLS** | Encryption protocols for HTTPS |
| **ACM** | AWS Certificate Manager — free SSL certificates |
| **OAC** | Origin Access Control — allows only CloudFront to access S3 |
| **SPA** | Single Page Application — JavaScript app with client-side routing |

### 📖 Further Learning

**Blog Posts:**
- [What is a CDN? - Cloudflare](https://www.cloudflare.com/learning/cdn/what-is-a-cdn/)
- [CloudFront + S3 Static Website - AWS Tutorial](https://docs.aws.amazon.com/AmazonCloudFront/latest/DeveloperGuide/GettingStarted.SimpleDistribution.html)
- [HTTPS Explained](https://howhttps.works/)
- [Cache-Control Headers Explained](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Cache-Control)

**Videos:**
- [CDN Explained - Fireship](https://www.youtube.com/watch?v=RI9np1LWzqw)
- [AWS CloudFront Tutorial - Stephane Maarek](https://www.youtube.com/watch?v=AT-nHW3_SVI)
- [HTTPS in 100 Seconds - Fireship](https://www.youtube.com/watch?v=X_FfLpkWQYE)
- [How SSL Certificates Work](https://www.youtube.com/watch?v=T4Df5_cojAs)

---

## 10. DevOps Practices — CI/CD, Versioning, Cost Management, Observability

### 🧠 The Concept

**DevOps** merges development and operations — automating the process of building, testing, and deploying code.

**Key practices:**
1. **CI/CD** — Continuous Integration / Continuous Deployment
2. **Versioning** — Track code changes and deployments
3. **Observability** — Monitor system health (logs, metrics, traces)
4. **Cost Management** — Track and optimize cloud spending
5. **Infrastructure as Code** — You've already learned this!

### 🎯 Mental Model

Think of DevOps like a **factory assembly line**:
- **Traditional approach** = Handcraft each product (slow, error-prone)
- **DevOps** = Automated assembly line (fast, consistent, quality-checked)

### 📂 In This Codebase

#### CI/CD Pipeline (Script-Based)
This project uses **shell scripts** instead of a CI/CD service (GitHub Actions, GitLab CI, Jenkins).

**Deployment workflow:**
[cli/deploy-app.sh](../cli/deploy-app.sh) lines 1-150:

```bash
#!/bin/bash

# 1. Get current version from ECR
CURRENT_VERSION=$(get_latest_version kuno/backend)

# 2. Increment version
NEW_VERSION=$(increment_version $CURRENT_VERSION patch)

# 3. Build Docker image
docker build --platform linux/amd64 \
  -t $ECR_REPO:$NEW_VERSION \
  -t $ECR_REPO:latest \
  -f Dockerfile \
  .

# 4. Push to ECR
docker push $ECR_REPO:$NEW_VERSION
docker push $ECR_REPO:latest

# 5. Update ECS service
TASK_DEF=$(aws ecs describe-task-definition \
  --task-definition kuno-main-backend \
  --query 'taskDefinition')

# Update image field in JSON
NEW_TASK_DEF=$(echo $TASK_DEF | jq \
  ".containerDefinitions[0].image = \"$ECR_REPO:$NEW_VERSION\"")

# Register new task definition
aws ecs register-task-definition --cli-input-json "$NEW_TASK_DEF"

# Force ECS to deploy new task definition
aws ecs update-service \
  --cluster kuno-main-cluster \
  --service kuno-main-backend-service \
  --force-new-deployment
```

**What happens:**
1. **Build** — Docker image created locally
2. **Tag** — Versioned (`1.2.3`), `latest`, and timestamped
3. **Push** — Upload to ECR
4. **Deploy** — ECS pulls new image and rolls out update

**Usage:**
```bash
./kc deploy backend auto    # Auto-increment: 1.2.3 → 1.2.4
./kc deploy backend minor   # Minor bump: 1.2.4 → 1.3.0
./kc deploy backend major   # Major bump: 1.3.0 → 2.0.0
./kc deploy backend 1.5.0   # Specific version
```

#### Semantic Versioning
[cli/utils/version.sh](../cli/utils/version.sh) implements **semver**:

**Version format:** `MAJOR.MINOR.PATCH`
- **MAJOR** — Breaking changes (users must update)
- **MINOR** — New features (backward compatible)
- **PATCH** — Bug fixes (no new features)

```bash
# Get latest version from ECR
get_latest_version() {
  local repo=$1
  aws ecr describe-images --repository-name $repo \
    --query 'sort_by(imageDetails, &imagePushedAt)[-1].imageTags[0]' \
    --output text
}

# Increment version
increment_version() {
  local version=$1
  local bump_type=$2  # patch, minor, major
  
  IFS='.' read -r major minor patch <<< "$version"
  
  case $bump_type in
    patch) patch=$((patch + 1)) ;;
    minor) minor=$((minor + 1)); patch=0 ;;
    major) major=$((major + 1)); minor=0; patch=0 ;;
  esac
  
  echo "$major.$minor.$patch"
}
```

**Example progression:**
```
0.0.1 → 0.0.2 → 0.0.3 → 0.1.0 → 0.2.0 → 1.0.0 → 1.0.1 → 1.1.0 → 2.0.0
```

#### Environment Promotion (Dev → Prod)
[kc-prod](../kc-prod) lines 353-431:

```bash
promote_command() {
  local service=$1
  local version=$2
  
  # Get ECR repository
  REPO_URL=$(aws ecr describe-repositories \
    --repository-names kuno/${service} \
    --query 'repositories[0].repositoryUri' \
    --output text)
  
  # Pull dev image
  docker pull ${REPO_URL}:${version}
  
  # Re-tag as 'prod'
  docker tag ${REPO_URL}:${version} ${REPO_URL}:prod
  
  # Push prod tag
  docker push ${REPO_URL}:prod
  
  # Ask if user wants to deploy
  read -p "Deploy to production now? (yes/no): " response
  if [ "$response" = "yes" ]; then
    aws ecs update-service \
      --cluster kuno-prod-cluster \
      --service kuno-prod-${service}-service \
      --force-new-deployment
  fi
}
```

**Workflow:**
```bash
# 1. Dev: Build and test
./kc deploy backend auto    # Creates version 0.0.15

# 2. Dev: Test version 0.0.15
./kc status backend         # Verify it's running

# 3. Prod: Check available versions
./kc-prod versions backend  # See 0.0.15 is available

# 4. Prod: Promote to prod
./kc-prod promote backend 0.0.15  # Tag as 'prod' and deploy
```

**Why this pattern?**
- Dev uses `latest` (always newest)
- Prod uses `prod` tag (explicitly promoted)
- Old prod version stays available for rollback

#### Service Control (Cost Optimization)
[cli/service-control.sh](../cli/service-control.sh) lines 1-80:

```bash
start_service() {
  local service=$1
  aws ecs update-service \
    --cluster $CLUSTER_NAME \
    --service ${SERVICE_PREFIX}-${service}-service \
    --desired-count 1
}

stop_service() {
  local service=$1
  aws ecs update-service \
    --cluster $CLUSTER_NAME \
    --service ${SERVICE_PREFIX}-${service}-service \
    --desired-count 0
}

status_service() {
  local service=$1
  aws ecs describe-services \
    --cluster $CLUSTER_NAME \
    --services ${SERVICE_PREFIX}-${service}-service \
    --query 'services[0].[serviceName,status,desiredCount,runningCount]'
}
```

**Usage:**
```bash
# Stop RAG1 when not needed (save ~$20/month)
./kc stop rag1

# Start before using
./kc start rag1

# Check status
./kc status rag1
```

#### Cost Management
**1. Real-Time Cost Tracking**
[cli/cost-current.sh](../cli/cost-current.sh) lines 1-100:

```bash
#!/bin/bash

# Get costs for last 4 days
START_DATE=$(date -d '4 days ago' '+%Y-%m-%d')
END_DATE=$(date '+%Y-%m-%d')

# Query AWS Cost Explorer
aws ce get-cost-and-usage \
  --time-period Start=${START_DATE},End=${END_DATE} \
  --granularity DAILY \
  --metrics "UnblendedCost" \
  --group-by Type=DIMENSION,Key=SERVICE \
  --filter file://<(cat <<EOF
{
  "Tags": {
    "Key": "Environment",
    "Values": ["dev", "prod"]
  }
}
EOF
) \
  --query 'ResultsByTime[*].[TimePeriod.Start, Groups[*].[Keys[0], Metrics.UnblendedCost.Amount]]' \
  --output table
```

**Output:**
```
--------------------------------------------------------------
|                      GetCostAndUsage                       |
+------------+-------------------------+----------------------+
| 2024-02-23 | EC2-Instances           | 1.23                 |
|            | RDS                     | 0.45                 |
|            | S3                      | 0.02                 |
+------------+-------------------------+----------------------+
| 2024-02-24 | EC2-Instances           | 1.25                 |
|            | RDS                     | 0.45                 |
+------------+-------------------------+----------------------+
Total: $3.40
```

**2. Cost Predictions with Infracost**
[cli/cost-predict.sh](../cli/cost-predict.sh):

```bash
#!/bin/bash

# Install Infracost (if needed)
# brew install infracost

# Generate cost breakdown
infracost breakdown \
  --path environments/dev \
  --format table

# Compare dev vs prod
infracost diff \
  --path environments/dev \
  --compare-to environments/prod
```

**Output:**
```
 Name                                     Monthly Qty  Unit   Monthly Cost 
                                                                            
 module.vpc.aws_nat_gateway.main                                           
 ├─ NAT gateway                                   730  hours        $32.85 
 └─ Data processed                         1,000,000  GB          $100.00 
                                                                            
 module.kuno_backend_service.aws_ecs_service                               
 ├─ vCPU (0.25 vCPU)                              730  hours         $9.13 
 └─ Memory (512 MB)                               730  GB-hours      $5.00 
                                                                            
 module.postgres.aws_db_instance                                           
 └─ db.t3.micro                                   730  hours        $15.00 
                                                                            
 OVERALL TOTAL                                                     $161.98 
```

**3. Budget Alerts**
[environments/dev/billing.tf](../environments/dev/billing.tf) lines 1-60:

```hcl
resource "aws_budgets_budget" "monthly" {
  name              = "kuno-main-monthly-budget"
  budget_type       = "COST"
  limit_amount      = "121.00"  # $121/month
  limit_unit        = "USD"
  time_unit         = "MONTHLY"
  
  notification {
    comparison_operator        = "GREATER_THAN"
    threshold                  = 50  # Alert at 50%
    threshold_type             = "PERCENTAGE"
    notification_type          = "ACTUAL"
    subscriber_email_addresses = [var.billing_alert_email]
  }
  
  notification {
    comparison_operator        = "GREATER_THAN"
    threshold                  = 100  # Alert at 100%
    threshold_type             = "PERCENTAGE"
    notification_type          = "FORECASTED"
    subscriber_email_addresses = [var.billing_alert_email]
  }
}

resource "aws_cloudwatch_metric_alarm" "billing" {
  alarm_name          = "kuno-main-high-billing"
  comparison_operator = "GreaterThanThreshold"
  evaluation_periods  = "1"
  metric_name         = "EstimatedCharges"
  namespace           = "AWS/Billing"
  period              = "21600"  # 6 hours
  statistic           = "Maximum"
  threshold           = "121.00"
  alarm_description   = "Alert when estimated charges exceed $121"
  alarm_actions       = [aws_sns_topic.billing_alerts.arn]
}
```

**Alerts sent when:**
- ✅ 50% of monthly budget used ($60.50)
- ✅ 100% of monthly budget used ($121)
- ✅ Forecast predicts exceeding budget
- ✅ Actual charges exceed $121

#### Observability — Logs, Metrics, Traces

**1. CloudWatch Logs**
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 100-108:

```hcl
resource "aws_cloudwatch_log_group" "service" {
  name              = "/ecs/${var.project_name}-${var.service_name}"
  retention_in_days = 14  # Keep logs for 2 weeks
}
```

**View logs:**
```bash
# Tail logs (live)
aws logs tail /ecs/kuno-main-backend --follow

# Last 1 hour
aws logs tail /ecs/kuno-main-backend --since 1h

# Filter by error
aws logs tail /ecs/kuno-main-backend --filter-pattern "ERROR"

# Specific time range
aws logs tail /ecs/kuno-main-backend \
  --start-time '2024-02-26T10:00:00' \
  --end-time '2024-02-26T11:00:00'
```

**2. Health Checks**
[modules/ecs_service/main.tf](../modules/ecs_service/main.tf) lines 140-148:

```hcl
healthCheck = {
  command     = ["CMD-SHELL", "curl -f http://localhost:3000/health || exit 1"]
  interval    = 30   # Check every 30 seconds
  timeout     = 5    # Wait 5 seconds for response
  retries     = 3    # Retry 3 times before marking unhealthy
  startPeriod = 60   # Wait 60 seconds before starting checks
}
```

**What happens if unhealthy?**
1. ECS stops sending traffic to the container
2. ECS starts a new container
3. Once new container is healthy, ECS kills the old one

**3. Service Discovery**
[modules/qdrant_cluster/main.tf](../modules/qdrant_cluster/main.tf) lines 110-135:

```hcl
resource "aws_service_discovery_private_dns_namespace" "main" {
  name = "kuno-main.local"
  vpc  = var.vpc_id
}

resource "aws_service_discovery_service" "qdrant" {
  name = "qdrant"
  
  dns_config {
    namespace_id = aws_service_discovery_private_dns_namespace.main.id
    
    dns_records {
      ttl  = 10
      type = "A"
    }
  }
}
```

**Usage:**
- Backend connects to `qdrant.kuno-main.local:6333`
- AWS automatically resolves to the Qdrant container's IP
- If Qdrant restarts (new IP), DNS updates automatically

#### Database Migrations
[migrations.md](../migrations.md) documents the migration workflow:

**Automatic migrations on startup:**
```typescript
// In backend server.ts
async function runMigrations() {
  if (process.env.DROP_DATABASE === 'true') {
    await sql`DROP SCHEMA public CASCADE; CREATE SCHEMA public;`;
  }
  
  const db = drizzle(pool);
  await migrate(db, { migrationsFolder: './packages/db/src/migrations' });
}
```

**Manual migrations via container:**
```bash
# Connect to database inside backend container
./kc exec 'apt-get update -qq && apt-get install -y -qq postgresql-client && psql $DATABASE_URL'

# Check tables
\dt

# Run SQL
SELECT * FROM users LIMIT 10;
```

### 🔑 Key Terms

| Term | Definition |
|---|---|
| **DevOps** | Culture/practice combining development and operations |
| **CI/CD** | Continuous Integration / Continuous Deployment (automated build/deploy) |
| **Semantic Versioning** | Version format: MAJOR.MINOR.PATCH |
| **Rollback** | Revert to a previous version |
| **Blue-Green Deployment** | Run two versions simultaneously, switch traffic |
| **Rolling Deployment** | Gradually replace old containers with new ones (zero downtime) |
| **Observability** | Ability to understand system state from outputs (logs, metrics, traces) |
| **Health Check** | Automated test to verify service is working |
| **Service Discovery** | Automatic DNS for microservices |
| **Cost Optimization** | Reducing cloud spending without sacrificing functionality |

### 📖 Further Learning

**Blog Posts:**
- [What is DevOps? - Atlassian](https://www.atlassian.com/devops)
- [CI/CD Pipeline Explained](https://www.redhat.com/en/topics/devops/what-is-ci-cd)
- [Semantic Versioning Spec](https://semver.org/)
- [The Twelve-Factor App](https://12factor.net/)
- [Observability Best Practices](https://www.honeycomb.io/what-is-observability)

**Videos:**
- [DevOps Explained in 100 Seconds - Fireship](https://www.youtube.com/watch?v=scEDHsr3APg)
- [CI/CD in 100 Seconds - Fireship](https://www.youtube.com/watch?v=scEDHsr3APg)
- [Zero Downtime Deployment - TechWorld with Nana](https://www.youtube.com/watch?v=0o0xCGZj1YM)
- [CloudWatch Tutorial - AWS Official](https://www.youtube.com/watch?v=a4dhoTQCyRA)
- [Complete DevOps Roadmap - freeCodeCamp](https://www.youtube.com/watch?v=9pZ2xmsSDdo)

---

## 🎓 Next Steps: Your DevOps Learning Path

You've completed the guide! Here's how to continue your journey:

### 1. **Hands-On Practice**
- Deploy a test app using this infrastructure
- Make small changes (add an environment variable, change CPU/memory)
- Break something intentionally, then fix it (great way to learn!)

### 2. **Expand Infrastructure Knowledge**
- Learn Kubernetes (EKS) — for larger-scale container orchestration
- Study AWS Lambda — serverless computing (no containers)
- Explore Infrastructure Testing (Terratest, Checkov)
- Learn GitOps (FluxCD, ArgoCD) — Git as source of truth for deployments

### 3. **Master Observability**
- Set up Grafana + Prometheus for detailed metrics
- Learn OpenTelemetry for distributed tracing
- Study log aggregation (ELK stack, Datadog, New Relic)

### 4. **Certifications** (Optional but valuable)
- **AWS Certified Solutions Architect - Associate** — Validates AWS knowledge
- **Terraform Associate** — Validates IaC skills
- **Linux Foundation Certified Kubernetes Administrator (CKA)** — For Kubernetes

### 5. **Follow DevOps Leaders**
- Kelsey Hightower (Google Cloud, Kubernetes)
- Martin Fowler (Software Architecture)
- Charity Majors (Observability, Honeycomb)
- Corey Quinn (AWS costs, humor)

### 6. **Community Resources**
- [r/devops](https://reddit.com/r/devops) — Reddit community
- [DevOps subreddit](https://reddit.com/r/kubernetes) — Kubernetes-specific
- [CNCF Slack](https://slack.cncf.io/) — Cloud Native Computing Foundation
- [HashiCorp Community](https://discuss.hashicorp.com/) — Terraform help

---

## 📝 Checklist: Understanding This Infrastructure

Mark your progress:

### Beginner Level
- [ ] Can explain what cloud infrastructure is
- [ ] Understand AWS regions and availability zones
- [ ] Can describe what VPC, subnets, security groups do
- [ ] Know difference between RDS, Redis, S3, EFS
- [ ] Can read basic Terraform code (variables, resources, outputs)

### Intermediate Level
- [ ] Can modify existing Terraform modules
- [ ] Understand ECS Fargate and how containers work
- [ ] Can deploy backend and frontend manually
- [ ] Know how secrets are managed (SSM Parameter Store)
- [ ] Understand IAM roles vs users vs policies

### Advanced Level
- [ ] Can write new Terraform modules from scratch
- [ ] Understand state management and locking
- [ ] Can troubleshoot deployment failures
- [ ] Know how CloudFront + S3 + Route53 work together
- [ ] Can optimize costs and set up monitoring

### Expert Level
- [ ] Can design multi-region architecture
- [ ] Understand CI/CD pipeline design
- [ ] Can implement zero-downtime deployments
- [ ] Know how to scale infrastructure (auto-scaling, load balancing)
- [ ] Can perform disaster recovery and incident response

---

## 🎯 Summary: What You Learned

| Chapter | Key Takeaway |
|---|---|
| **1. What Is Cloud** | Renting computing resources instead of buying hardware |
| **2. AWS Foundations** | Regions, AZs, and core services (compute, storage, networking) |
| **3. Networking** | VPC isolates your network; subnets, SGs, and ALB control traffic |
| **4. Compute** | Containers package apps; ECS Fargate runs them without managing servers |
| **5. Databases** | RDS for structured data, Redis for cache, S3 for files, EFS for persistent volumes |
| **6. Terraform Basics** | Infrastructure as Code — define infrastructure in files, version control it |
| **7. Terraform Advanced** | Modules for reusability; remote state for collaboration |
| **8. Security** | SSM for secrets; IAM for access control; least privilege principle |
| **9. Frontend** | S3 + CloudFront + ACM for fast, secure static site delivery |
| **10. DevOps** | Automate build/deploy; version everything; monitor costs and health |

---

## 💡 Final Thoughts

You now have a **production-grade template** for cloud infrastructure. This repository demonstrates:

✅ **Best practices** — Multi-AZ, encrypted data, least privilege, infrastructure as code  
✅ **Real-world patterns** — Secrets management, CI/CD, cost optimization, monitoring  
✅ **Scalability** — Modular design allows adding services easily  
✅ **Security** — Private subnets, security groups, IAM roles, TLS everywhere  

**Remember:** DevOps is a journey, not a destination. You'll learn the most by:
1. **Building** — Create projects, deploy them
2. **Breaking** — Intentionally break things to understand how they work
3. **Fixing** — Debug issues, read error messages carefully
4. **Asking** — Join communities, ask questions, help others

Happy learning! 🚀

---

**Questions or feedback?** Open an issue in this repository or contribute improvements to this guide.
