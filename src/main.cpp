#include "renderer/openGL/shader.h"
#include "renderer/openGL/vertexBuffer.h"
#include "renderer/openGL/vertexArray.h"
#include "renderer/renderer.h"
#include "window.h"

#include <glad/glad.h>

#include <iostream>
#include <cstdlib>

int main()
{
    Syrus::Window window(800, 600, "My Window!");

    // Load OpenGL functions.
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    Syrus::Shader shader("src/shader.vs", "src/shader.fs");

    float vertices[] =
    {
        // Positions.           // Colors.
         -1.0f, -1.0f, 0.0f,     1.0f, 0.0f, 0.0f,
          0.0f, -1.0f, 0.0f,     0.0f, 1.0f, 0.0f,
         -0.5f,  0.0f, 0.0f,     0.0f, 0.0f, 1.0f,

         // Positions.           // Colors.
         1.0f, 1.0f, 0.0f,     1.0f, 1.0f, 0.0f,
         0.0f, 1.0f, 0.0f,     1.0f, 0.0f, 1.0f,
         0.5f, 0.0f, 0.0f,     0.5f, 0.5f, 1.0f
    };

    Syrus::VertexBuffer VBO(vertices);
    Syrus::VertexArray VAO({ 3, 3 });

    VBO.unbind();

    // Draw wireframe if desired.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    Syrus::Renderer renderer;

    // Render loop
    while (window.isRunning())
    {
        // Handle input.
        window.processInput();

        // Render
        renderer.clear(1.0f, 1.0f, 0.0f, 1.0f);

        shader.use();

        VAO.bind();

        renderer.draw(VBO, VAO, shader); // bind in fn?

        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}
