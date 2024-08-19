/**
 * This class represents a vertex buffer which represents a block of data
 * containing information about vertices and their attributes such as position,
 * color, texture, etc. However, it specifies no information about the layout
 * of this data - it only contains the data itself.
 */
#pragma once

#include <glad/glad.h>

#include <span>

namespace Syrus
{
	class VertexBuffer
	{
	public:
		/**
		 * @brief This constructor generates a unique ID for the vertex buffer,
		 * binds it to the active array buffer bind point, and populates the
		 * buffer with the vertex data. Span is used to allow any contiguous
		 * data structure to be used for the vertex data such as C-style
		 * arrays, C++ arrays, and vectors.
		 *
		 * @param vertices The vertex data.
		 * @param usage Specifies how the graphics card should manage the
		 * vertices.
		 *
		 * Static (default) data is set once and used many times.
		 * Dynamic data is changed many times and used many times.
		 * Stream data is set once and used only a few times.
		 */
		VertexBuffer(const std::span<GLfloat>& vertices,
			GLenum usage = GL_STATIC_DRAW);

		/**
		 * This destructor deletes the vertex buffer and allows the unique ID
		 * to be used again.
		 */
		~VertexBuffer();

		/**
		 * @brief Binds the vertex buffer to the active array buffer bind
		 * point.
		 */
		void bind() const;

		/**
		 * @brief Unbinds the vertex buffer to the active array buffer bind
		 * point.
		 */
		void unbind() const;

		/**
		 * @brief Unbinds the vertex buffer to the active array buffer bind
		 * point.
		 */
		inline int getTotalFloats() const { return m_numTotalFloats; }

	private:
		/**
		 * @brief Represents the unique, OpenGL ID for the vertex buffer.
		 */
		GLuint m_ID;

		/**
		 * @brief The number of floats in the vertex buffer.
		 */
		int m_numTotalFloats;
	};
}
