//
// Created by nathan on 10/18/20.
//

#ifndef GAMEBOY___EMULATOR_H
#define GAMEBOY___EMULATOR_H

#include "GL/glew.h"
#include "GLContext.h"

class Emulator {

public:
    Emulator();
    GLboolean getShouldQuit() const;
    void tick();

private:
    void draw() const;

    GLboolean shouldQuit;
    GLContext glContext;

    void poll();
};


#endif //GAMEBOY___EMULATOR_H
