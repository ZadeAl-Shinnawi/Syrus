#include "window.h"
#include "renderer/renderer.h"
#include "renderer/openGL/shader.h"
#include "renderer/openGL/texture.h"
#include "renderer/openGL/vertexBuffer.h"
#include "renderer/openGL/vertexArray.h"

#include <array>

int main()
{
    Syrus::Window window(800, 600, "My Window!");

    Syrus::Shader shader("src/shaders/shader.vs", "src/shaders/shader.fs");

    std::array<float, 32> vertices =
    {
        // Positions.          // Colors.           // Texture coords.
        0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f,    1.0f, 1.0f,
        0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,    1.0f, 0.0f,
       -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,    0.0f, 0.0f,
       -0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 0.0f,    0.0f, 1.0f
    };

    std::array<unsigned int, 6> indices
    {
        0, 1, 3,
        1, 2, 3
    };

    Syrus::Texture container("resources/container.jpg");
    Syrus::Texture smiley("resources/awesomeface.png");

    container.bind(0);
    smiley.bind(1);

    Syrus::VertexBuffer VBO(vertices);

    // Three position floats, three color floats, two texture coords.
    Syrus::VertexArray VAO({ 3, 3, 2 });

    Syrus::IndexBuffer IBO(indices);

    Syrus::Renderer renderer;


    // Set texture uniforms.
    shader.use();
    shader.setUniformInt("ourTexture", 0);
    shader.setUniformInt("ourTexture2", 1);

    // Render loop.
    while (window.isRunning())
    {
        // Handle input.
        window.processInput();

        // Render.
        renderer.clear(0.0f, 0.2f, 0.4f, 1.0f);
        renderer.draw(VBO, VAO, IBO, shader);
        window.swapBuffers();

        // Poll events.
        window.pollEvents();
    }

    return 0;
}
