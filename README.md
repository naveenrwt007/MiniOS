# 💻 Mini Operating System  

A basic custom-built operating system with core functionalities like memory management, file system, and command-line interface.

---

## ✨ Features  

### 🧠 Core OS Functionality  

- Memory Management: Handles allocation and deallocation  
- Process Handling: Basic execution control  
- File System: CRUD operations  
- Bootable System  

---

### 💻 Shell Interface  

- Command-line Interface  
- Custom commands  
- Input handling  

---

## 🚀 Quick Start  

### 1. Clone  

```bash
git clone https://github.com/naveenrwt007/MiniOS.git
cd MiniOS
```

### 2. Compile the Code

gcc -o minios main.c

### 3. Run the OS

./minios

## 📁 Project Structure

MiniOS/
├── kernel/ # Core OS logic
├── memory/ # Memory management
├── filesystem/ # File system
├── shell/ # Command-line interface
├── drivers/ # Hardware interaction
├── main.c # Entry point
├── Makefile # Build file
└── README.md # Documentation
