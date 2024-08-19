/**
 * This class represents an index buffer which contains indices to be drawn in
 * order. This is useful when multiple indices are shared by a primitive, so
 * that they are not drawn multiple times.
 */
#pragma once

#include <glad/glad.h>

#include <span>

namespace Syrus
{
	class IndexBuffer
	{
	public:
		/**
		 * @brief This constructor generates a unique ID for the index buffer,
		 * binds it to the active element array buffer bind point, and
		 * populates the buffer with the index data. Span is used to allow any
		 * contiguous data structure to be used for the index data such as
		 * C-style arrays, C++ arrays, and vectors.
		 *
		 * @param indices The index values to be drawn in order.
		 * @param usage Specifies how the graphics card should manage the
		 * indices.
		 *
		 * Static (default) data is set once and used many times.
		 * Dynamic data is changed many times and used many times.
		 * Stream data is set once and used only a few times.
		 */
		IndexBuffer(const std::span<GLfloat>& indices,
			GLenum usage = GL_STATIC_DRAW);

		/**
		 * This destructor deletes the index buffer and allows the unique ID to
		 * be used again.
		 */
		~IndexBuffer();

		/**
		 * @brief Binds the index buffer to the active element array buffer
		 * bind point.
		 */
		void bind() const;

		/**
		 * @brief Unbinds the index buffer from the active element array buffer
		 * bind point.
		 */
		void unbind() const;

	private:
		/**
		 * @brief Represents the unique, OpenGL ID for the index buffer.
		 */
		GLuint m_ID;
	};
}
