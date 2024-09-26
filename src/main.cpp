#include "renderer/openGL/shader.h"
#include "renderer/openGL/vertexBuffer.h"
#include "renderer/openGL/vertexArray.h"
#include "renderer/renderer.h"
#include "window.h"

#include <array>

int main()
{
    Syrus::Window window(800, 600, "My Window!");

    Syrus::Shader shader("src/shaders/shader.vs", "src/shaders/shader.fs");

    std::array<float, 18> vertices =
    {
        // Positions.           // Colors.
        -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f,     0.0f, 0.0f, 1.0f
    };

    Syrus::VertexBuffer VBO(vertices);

    // Three position floats and three color floats.
    Syrus::VertexArray VAO({ 3, 3 });

    Syrus::Renderer renderer;

    // Render loop.
    while (window.isRunning())
    {
        // Handle input.
        window.processInput();

        // Render.
        renderer.clear(1.0f, 1.0f, 0.0f, 1.0f);
        renderer.draw(VBO, VAO, shader);
        window.swapBuffers();

        // Poll events.
        window.pollEvents();
    }

    return 0;
}
