#include "init.h"
#include "sig.h"
#include "time.h"
#include "interrupt.h"
#include "acpi.h"
#include "sysklog.h"
#include "process.h"

uint8_t RUNLEVEL = RUNLEVEL_HALT;

void init_switch_0() {
    RUNLEVEL = RUNLEVEL_HALT;
    sig_all(SIGTERM);
    time_wait(process_getpid(), 5);
    sig_all(SIGKILL);
    __asm__("hlt");
}
void init_switch_1() {
    RUNLEVEL = RUNLEVEL_SINGLE_USER;
    interrupt_soft_runlevel(1);
}
void init_switch_2() {
    RUNLEVEL = RUNLEVEL_MULTI_USER;
    interrupt_soft_runlevel(2);
}
void init_switch_3() {
    RUNLEVEL = RUNLEVEL_MULTI_USER_NET;
    interrupt_soft_runlevel(3);
}
void init_switch_4() {
    RUNLEVEL = RUNLEVEL_SPECIAL;
    interrupt_soft_runlevel(4);
}
void init_switch_5() {
    RUNLEVEL = RUNLEVEL_GUI;
    interrupt_soft_runlevel(5);
}
void init_switch_6() {
    RUNLEVEL = RUNLEVEL_REBOOT;
    sig_all(SIGTERM);
    time_wait(process_getpid(), 5);
    sig_all(SIGKILL);
    acpi_reboot();
}