# MiniOS
MiniOS/
├── boot/
│   └── boot.s              # Assembly bootloader
├── kernel/
│   ├── kernel.c            # Kernel entry point
│   ├── interrupts.c/h      # Interrupt handling
│   ├── memory.c/h          # Memory management
│   └── scheduler.c/h       # (Later) Process scheduling
├── drivers/
│   ├── keyboard.c/h
│   └── screen.c/h
├── lib/
│   └── stdio.c/h           # Minimal C library functions
├── Makefile
└── README.md


# MiniOS

MiniOS is a lightweight educational operating system built from scratch in C. It features:

- Modular shell interface
- Process management
- File system abstraction
- Memory management
- Utilities and history tracking

## Build

```bash
make
./MiniOS
