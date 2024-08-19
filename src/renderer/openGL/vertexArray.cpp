#include "vertexArray.h"

#include <glad/glad.h>

#include <numeric>
#include <iostream>
#include <initializer_list>

namespace Syrus
{
	VertexArray::VertexArray(const std::initializer_list<unsigned int>& vertexAttributes) : m_vertexAttributes(vertexAttributes)
	{
		glGenVertexArrays(1, &m_ID);

		m_numAttributeFloats = std::accumulate(m_vertexAttributes.begin(), m_vertexAttributes.end(), 0);

		glBindVertexArray(m_ID); // fn?

		unsigned int offset = 0;
		unsigned int i = 0;
		for (unsigned int attribute : m_vertexAttributes)
		{
			glVertexAttribPointer(i, attribute, GL_FLOAT, GL_FALSE, m_numAttributeFloats * sizeof(float), reinterpret_cast<void*>(offset));
			glEnableVertexAttribArray(i);

			offset += sizeof(float) * attribute;
			++i;
		}

		glBindVertexArray(0); // fn?
		////std::cout << m_vertexAttributes.si;
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_ID);
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_ID);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}
}
