//
// Created by nathan on 10/18/20.
//

#include "Emulator.h"

Emulator::Emulator():
    shouldQuit(false){
}

void Emulator::tick(){
    GLenum error = glGetError();
    if(error != GL_NO_ERROR){
        std::cout << "GL Error: " << error << std::endl;
    }
    poll();
    draw();
}

GLboolean Emulator::getShouldQuit() const {
    return shouldQuit;
}

void Emulator::draw() const {
    GLfloat vertices[] = {
            0.0f, 0.5f,
            0.5f, -0.5f,
            -0.5f, -0.5f,
    };
    glContext.draw(vertices);
}

void Emulator::poll() {
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT){
            shouldQuit = true;
        }
    }
}
