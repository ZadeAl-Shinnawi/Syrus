/**
 * This class represents a vertex buffer which represents a block of data
 * containing information about vertices and their attributes such as position,
 * color, texture, etc. However, it specifies no information about the layout
 * of this data - it only contains the data itself.
 */
#pragma once

#include <glad/glad.h>

#include <span>
#include <cstddef>

namespace Syrus
{
	class VertexBuffer
	{
	public:
		VertexBuffer(const std::span<GLfloat>& vertices,
			GLenum usage = GL_STATIC_DRAW);

		~VertexBuffer();

		void bind() const;

		void unbind() const;

		// Returns the total number of floats in the vertex buffer.
		inline std::size_t getTotalFloats() const { return m_numTotalFloats; }

	private:
		GLuint m_ID;

		// The total number of floats in the vertex buffer.
		std::size_t m_numTotalFloats;
	};
}
