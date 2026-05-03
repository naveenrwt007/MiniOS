💻 Mini Operating System

A basic custom-built operating system with core functionalities like memory management, file system, and command-line interface.

✨ Features
🧠 Core OS Functionality
Memory Management: Handles allocation and deallocation of memory
Process Handling: Basic process execution and control
File System: Create, read, update, and delete files
Bootable System: Runs from boot (USB/ISO-based execution)
💻 Shell Interface
Command-line Interface (CLI)
Custom Commands Support
User Input Handling
Basic system-level operations
📁 File Management
File creation and deletion
Directory structure handling
Read/write operations
File navigation commands
⚙️ System Components
Kernel-level logic implementation
Memory manager module
File system module
Command interpreter
🎨 System Design
Modular architecture
Clean separation of components
Lightweight and efficient
Easy to extend with new features
🚀 Quick Start
1. Clone the Repository
git clone https://github.com/naveenrwt007/MiniOS.git
cd MiniOS
2. Compile the Code

(Example – adjust based on your project)

gcc -o minios main.c
3. Run the OS
./minios

OR (if bootable):

Create bootable USB
Boot system using MiniOS
📁 Project Structure
MiniOS/
├── kernel/           # Core OS logic
├── memory/           # Memory management module
├── filesystem/       # File system implementation
├── shell/            # Command-line interface
├── drivers/          # Hardware interaction (if any)
├── main.c            # Entry point
├── Makefile          # Build configuration
└── README.md         # Documentation
🔧 Commands (Shell)
help → Show available commands
ls → List files
create → Create file
delete → Delete file
run → Execute program
clear → Clear screen
🎯 How to Use
User Flow:
Boot the MiniOS
Access command-line interface
Run commands like file operations
Manage memory and processes
🧠 System Modules
Core Modules
Kernel: Handles system execution
Memory Manager: Allocates memory
File System: Stores and retrieves data
Shell: Interface for user interaction
🔒 Features & Limitations
✅ Implemented
Basic OS structure
CLI-based interaction
File handling system
Memory handling
❌ Not Yet Implemented
GUI interface
Multi-user system
Networking support
Advanced scheduling
🚀 Future Enhancements
Graphical User Interface (GUI)
Process Scheduling Algorithms (FCFS, Round Robin)
Multi-threading support
Device driver expansion
Networking capabilities
🧪 Testing
Test command execution
Verify file operations
Check memory allocation
Run multiple commands sequentially
❓ Troubleshooting
Common Issues

Compilation Error

Ensure GCC is installed
Check file paths

Program not running

Verify build output
Check execution permissions

Commands not working

Validate shell input handling
Debug command parser
🎉 Ready to Use!

Your Mini Operating System includes:

✅ Core OS functionality
✅ Command-line interface
✅ Memory management
✅ File system
✅ Modular architecture

This project provides a strong foundation for understanding operating system concepts and building advanced OS features. 🚀
