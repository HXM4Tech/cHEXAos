#pragma once

#include <stdint.h>
#include <stddef.h>

enum {
    RUNLEVEL_HALT = 0,
    RUNLEVEL_SINGLE_USER = 1,
    RUNLEVEL_MULTI_USER = 2,
    RUNLEVEL_MULTI_USER_NET = 3,
    RUNLEVEL_SPECIAL = 4,
    RUNLEVEL_GUI = 5,
    RUNLEVEL_REBOOT = 6,
};

uint8_t RUNLEVEL;

void init_switch_0();
void init_switch_1();
void init_switch_2();
void init_switch_3();
void init_switch_4();
void init_switch_5();
void init_switch_6();
