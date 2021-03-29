#include "print.h"
#include "sysklog.h"

void sysklog_init() {
    print_clear();
    sysklog_ok("Sysklog initialized");
}

void sysklog_info(char* str) {
    if (print_get_col() != 0) { print_str("\n"); }

    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("[ ");
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);
    print_str("INFO");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str(" ] ");
    print_str(str);
    print_str("\n");
}

void sysklog_ok(char* str) {
    if (print_get_col() != 0) { print_str("\n"); }

    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("[  ");
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("OK");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("  ] ");
    print_str(str);
    print_str("\n");
}
void sysklog_warn(char* str) {
    if (print_get_col() != 0) { print_str("\n"); }

    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("[ ");
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("WARN");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str(" ] ");
    print_str(str);
    print_str("\n");
}

void sysklog_failed(char* str) {
    if (print_get_col() != 0) { print_str("\n"); }
    
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("[");
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("FAILED");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("] ");
    print_str(str);
    print_str("\n");
}