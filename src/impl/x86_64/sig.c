#include "sig.h"
#include "process.h"

void sig_all(uint8_t signal) {
    for (size_t i = 0; 1; i++) {
        int pid = (int) ALL_PIDS[i];

        if (pid == '\0') {
            return;
        }
        sig_pid(pid, signal);
    }
}

void sig_pid(int pid, uint8_t signal) {
    // TODO
}
