//
// Created by nathan on 10/18/20.
//

#ifndef GAMEBOY___DEFAULTSHADER_H
#define GAMEBOY___DEFAULTSHADER_H

#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class DefaultShader{
public:
    DefaultShader(){
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        loadShaders(vertexShader, fragmentShader);
        glCompileShader(vertexShader);
        glCompileShader(fragmentShader);
        logShaderStatus(vertexShader);
        logShaderStatus(fragmentShader);

        // Link the vertex and fragment shader into a shader program
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        glUseProgram(shaderProgram);
    }

    void logShaderStatus(GLuint shader){
        GLint status;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (!status){
            char buffer[512];
            glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
            std::cout <<"Error compiling shader:\n" << buffer << std::endl;
            return;
        }
        std::cout << "Successfully compiled shader." <<std::endl;
    }

    GLuint getVertexShader() const {
        return vertexShader;
    }

    GLuint getFragmentShader() const {
        return fragmentShader;
    }

    GLuint getShaderProgram() const {
        return shaderProgram;
    }

private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;

    void loadShaders(GLuint vertexShader, GLuint fragmentShader){
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vertexFile;
        std::ifstream fragmentFile;

        const std::string RELATIVE_PATH = "../Shaders/";
        vertexFile.open(RELATIVE_PATH + "vertexShader.glsl");
        fragmentFile.open(RELATIVE_PATH + "fragmentShader.glsl");

        std::stringstream vertexStream, fragmentStream;
        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexCode = vertexStream.str();
        fragmentCode = fragmentStream.str();

        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();

        glShaderSource(vertexShader, 1, &vShaderCode, NULL);
        glShaderSource(fragmentShader, 1, &fShaderCode, NULL);

    }

};

#endif //GAMEBOY___DEFAULTSHADER_H
