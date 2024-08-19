#include "window.h"

#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

namespace Syrus
{
    Window::Window(unsigned int width, unsigned int height,
        const std::string& title) : m_window(nullptr)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Create and error check window.
        m_window = glfwCreateWindow(width, height,
            title.c_str(), nullptr, nullptr);

        if (m_window == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            std::exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(m_window);
        glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::processInput()
    {
        if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(m_window, true);
        }
    }

    bool Window::isRunning()
    {
        return !glfwWindowShouldClose(m_window);
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    void Window::framebufferSizeCallback(GLFWwindow* window, int width,
        int height)
    {
        glViewport(0, 0, width, height);
    }
}
