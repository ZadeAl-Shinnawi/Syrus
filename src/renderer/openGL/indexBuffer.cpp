#include "indexBuffer.h"

#include <glad/glad.h>

#include <span>

namespace Syrus
{
	IndexBuffer::IndexBuffer(const std::span<GLuint>& indices, GLenum usage) :
		m_indices(indices)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			sizeof(GLuint) * m_indices.size(), m_indices.data(), usage);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void IndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}

	void IndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
