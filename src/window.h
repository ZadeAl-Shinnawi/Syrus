/**
 * This class represents a generic, multi-platform window handled by GLFW.
 */
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Syrus
{
	class Window
	{
	public:
		Window(unsigned int width, unsigned int height,
			const std::string& title);

		~Window();

		void processInput();

		bool isRunning();

		// Swaps the front and back buffers to avoid screen tearing.
		void swapBuffers();

		void pollEvents();

	private:
		GLFWwindow* m_window;

		static void framebufferSizeCallback(GLFWwindow* window, int width,
			int height);
	};
}
