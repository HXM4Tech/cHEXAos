#include "sysklog.h"
#include "print.h"
#include "init.h"
#include "convert.h"

static char* error_text = "Unknown error";

void kernel_main() {
    bootcode();
    sysklog_warn("Switching runlevel to 0 - HALTING!");
    init_switch_0();
}

void kernel_unexpected_exit() {
    sysklog_failed("Main kernel function has quit unexpectedly!");
    print_str("\n---------[KERNEL PANIC]---------\n");
    print_str("ERR: ");
    print_str(error_text);
    init_switch_0();
}

void bootcode() {
    sysklog_init(); // Clear screen and init sysklog (boot messages and dmesg)
    init_switch_1(); // Switch to runlevel 1
    sysklog_ok("Switched to runlevel 1");
    sysklog_info("Welcome to cHEXAos!"); // Display welcome message
}