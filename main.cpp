#define GLEW_STATIC
#include "Emulator.h"


int main() {
    Emulator emulator;
    while (!emulator.getShouldQuit()) {
        emulator.tick();
    }

    return 0;
}