#include <iostream>
#include <cstdlib>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main()
{
	// Initialize GLFW functions, version, and mode.
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create and error check window.
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My Window", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cout << "Failed to create OpenGL window" << std::endl;
		glfwTerminate();
		std::exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	// Load and error check OpenGL functions.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		std::exit(EXIT_FAILURE);
	}

	// Render loop.
	while (!glfwWindowShouldClose(window))
	{
		// Input.
		processInput(window);

		// Render.
		glClearColor(0.8f, 0.8f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Handle events.
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
