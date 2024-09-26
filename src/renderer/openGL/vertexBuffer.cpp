#include "vertexBuffer.h"

#include <glad/glad.h>

#include <span>

namespace Syrus
{
	// Generates a buffer, binds it, and populates it with vertex information.
	VertexBuffer::VertexBuffer(const std::span<GLfloat>& vertices,
		GLenum usage)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(),
			vertices.data(), usage);

		m_numTotalFloats = vertices.size();
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void VertexBuffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void VertexBuffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
