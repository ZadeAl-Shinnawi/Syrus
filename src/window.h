/**
 * This class represents a generic, multi-platform window handled by GLFW.
 */
#pragma once

#include <GLFW/glfw3.h>

#include <string>

namespace Syrus
{
	class Window
	{
	public:
		/**
		 * @brief This constructor initializes GLFW and sets the version.
		 * Version 3.3 and core-profile are enforced. This function also
		 * specifies the window dimensions and title, sets the window as
		 * the current context, and sets the frame buffer size callback
		 * to handle resizing of the window.
		 *
		 * @param width Specifies the width, in pixels, of the window.
		 * @param height Specifies the height, in pixels, of the window.
		 * @param title Specifies the title of the window.
		 */
		Window(unsigned int width, unsigned int height,
			const std::string& title);

		/**
		 * This destructor terminates GLFW which destroys all windows and
		 * cursors and frees any other allocated resources.
		 */
		~Window();

		/**
		 * @brief Checks whether the window should be closed via either
		 * pressing the close button with the mouse or the escape key on the
		 * keyboard.
		 */
		void processInput();

		/**
		 * @brief Checks whether the close flag has been set for the GLFW
		 * window.
		 */
		bool isRunning();

		///////////////////////
		/**
		 * @brief Swaps the front and back buffers to avoid screen tearing.
		 */
		void swapBuffers();

		/**
		 * @brief Processes all events in the event queue.
		 */
		void pollEvents();

	private:
		/**
		 * @brief Represents the underlying GLFW window.
		 */
		GLFWwindow* m_window;

		/**
		 * @brief Handles resizing of the window viewport.
		 *
		 * @param width Specifies the new width, in pixels, of the window.
		 * @param height Specifies the new height, in pixels, of the window.
		 */
		static void framebufferSizeCallback(GLFWwindow* window, int width,
			int height);
	};
}
