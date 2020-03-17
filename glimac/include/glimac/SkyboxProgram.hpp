#pragma once

#include "glm.hpp"
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

namespace glimac {

    class SkyBoxProgram {

    public :

        Program m_Program;

        GLint uMVMatrix;
        GLint uMVPMatrix;
        GLint uNormalMatrix;
        GLint uTexture;

        SkyBoxProgram(const FilePath& applicationPath):
            m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                  applicationPath.dirPath() + "shaders/3D.fs.glsl")) {
            uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
            uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
            uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
            uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        }
    };
}
