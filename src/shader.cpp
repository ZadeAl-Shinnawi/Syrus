#include "shader.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexShaderFilePath,
    const std::string& fragmentShaderFilePath) : m_ID(glCreateProgram())
{
    // Read in vertex shader file.
    std::ifstream vertexShaderFile(vertexShaderFilePath);
    std::stringstream vertexShaderStream;
    vertexShaderStream << vertexShaderFile.rdbuf();
    vertexShaderFile.close();
    std::string vertexShaderSourceString = vertexShaderStream.str();
    const char* vertexShaderSource = vertexShaderSourceString.c_str();

    // Create and compile vertex shader.
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    // Error check vertex shader compilation.
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog
            << std::endl;
    }

    // Read in fragment shader file.
    std::ifstream fragmentShaderFile(fragmentShaderFilePath);
    std::stringstream fragmentShaderStream;
    fragmentShaderStream << fragmentShaderFile.rdbuf();
    fragmentShaderFile.close();
    std::string fragmentShaderSourceString = fragmentShaderStream.str();
    const char* fragmentShaderSource = fragmentShaderSourceString.c_str();

    // Create and compile fragment shader.
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    // Error check fragment shader compilation.
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog
            << std::endl;
    }

    // Link vertex and fragment shaders.
    glAttachShader(m_ID, vertexShader);
    glAttachShader(m_ID, fragmentShader);
    glLinkProgram(m_ID);

    // Error check shader program linking.
    glGetProgramiv(m_ID, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(m_ID);
}

void Shader::use() const
{
    glUseProgram(m_ID);
}
