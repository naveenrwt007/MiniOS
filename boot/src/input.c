#include <stdint.h>

// BIOS interrupt to read a single key
char get_key() {
    char key;
    asm volatile (
        "mov $0x00, %%ah\n"   // BIOS: Read character
        "int $0x16\n"         // Keyboard interrupt
        "mov %%al, %0\n"      // Store result in key
        : "=r"(key)
        :
        : "ah", "al"
    );
    return key;
}

// VGA print single character with cursor tracking
void vga_print_char(char c) {
    static int row = 0, col = 0;
    volatile char* vga = (char*)0xB8000;

    if (c == '\n') {
        row++;
        col = 0;
        return;
    }

    int pos = (row * 80 + col) * 2;
    vga[pos] = c;
    vga[pos + 1] = 0x07;  // Light gray on black
    col++;
    if (col >= 80) {
        col = 0;
        row++;
    }
}

// Read full line from keyboard
void get_input(char* buffer) {
    int i = 0;
    char c;
    while (1) {
        c = get_key();

        // Enter key
        if (c == '\r') {
            vga_print_char('\n');
            break;
        }

        // Backspace
        if (c == '\b' && i > 0) {
            i--;
            // Move cursor back and overwrite with space
            vga_print_char('\b');
            vga_print_char(' ');
            vga_print_char('\b');
            continue;
        }

        // Printable character
        buffer[i++] = c;
        vga_print_char(c);
    }
    buffer[i] = '\0';
}