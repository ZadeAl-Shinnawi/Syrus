#include "renderer/openGL/shader.h"
#include "renderer/openGL/vertexBuffer.h"
#include "renderer/openGL/vertexArray.h"
#include "renderer/renderer.h"
#include "window.h"

// TEXTURE
#include "stb_image.h"
#include <iostream>

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

    // TEXTURE

    // Create texture object.
    unsigned int texture;
    glGenTextures(1, &texture);

    // Bind texture object.
    glBindTexture(GL_TEXTURE_2D, texture);

    // set the texture wrapping/filtering options (on currently bound texture)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load image.
    int width;
    int height;
    int channels;

    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

    unsigned char* data = stbi_load("resources/container.jpg", &width, &height, &channels, 0);

    // Generate texture if data is valid.
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
            GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    // Free image memory.
    stbi_image_free(data);


    unsigned int texture2;
    glGenTextures(1, &texture2);

    // Bind texture object.
    glBindTexture(GL_TEXTURE_2D, texture2);

    // Load texture #2.
    int width2;
    int height2;
    int channels2;
    unsigned char* data2 = stbi_load("resources/awesomeface.png", &width2, &height2,
        &channels2, 0);
    if (data2)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGBA,
            GL_UNSIGNED_BYTE, data2);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);


    Syrus::VertexBuffer VBO(vertices);

    // Three position floats, three color floats, two texture coords.
    Syrus::VertexArray VAO({ 3, 3, 2 });

    Syrus::IndexBuffer IBO(indices);

    Syrus::Renderer renderer;


    // Tex.
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
