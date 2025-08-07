#include <stdlib.h>
#include <windows.h>

bool is_legacy() {

    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;

    if (GetConsoleMode(hStdout, &mode))
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    return !SetConsoleMode(hStdout, mode);
}

bool randbool() { return rand() % (true + 1); }