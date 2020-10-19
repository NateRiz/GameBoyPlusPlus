//
// Created by nathan on 10/18/20.
//

#ifndef GAMEBOY___GLCONTEXT_H
#define GAMEBOY___GLCONTEXT_H

#include "Window.h"
#include "DefaultShader.h"

class GLContext{
public:
    GLContext(){
        // Create Vertex Array Object
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Create a Vertex Buffer Object and copy the vertex data to it
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        GLfloat vertices[] = {
                0.0f, 0.5f,
                0.5f, -0.5f,
                -0.5f, -0.5f,
        };
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);

        // Specify the layout of the vertex data
        GLint posAttrib = glGetAttribLocation(shader.getShaderProgram(), "position");
        glEnableVertexAttribArray(posAttrib);
        glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }

    virtual ~GLContext(){
        glDeleteProgram(shader.getShaderProgram());
        glDeleteShader(shader.getFragmentShader());
        glDeleteShader(shader.getVertexShader());
        glDeleteBuffers(1, &vbo);
        glDeleteVertexArrays(1, &vao);
    }

    void draw() const {
        // Clear the screen to black
        glClearColor(139.f/255.f, 172.f/255.f, 15.f/255.f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers
        SDL_GL_SwapWindow(window.getWindow());
    }


private:
    Window window;
    DefaultShader shader;
    GLuint vbo;
    GLuint vao;
};

#endif //GAMEBOY___GLCONTEXT_H
