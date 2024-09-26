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
		IndexBuffer(const std::span<GLfloat>& indices,
			GLenum usage = GL_STATIC_DRAW);

		~IndexBuffer();

		void bind() const;

		void unbind() const;

	private:
		GLuint m_ID;
	};
}
