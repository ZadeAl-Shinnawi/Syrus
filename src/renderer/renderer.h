/**
 * This class represents a generic renderer which will draw currently bound
 * objects based on the graphics API specified. Currently only supports OpenGL.
 */
#pragma once

#include "openGL/vertexBuffer.h"
#include "openGL/vertexArray.h"
#include "openGL/indexBuffer.h"
#include "openGL/shader.h"

#include <glad/glad.h>

namespace Syrus
{
	class Renderer
	{
	public:
		void draw(const VertexBuffer& vbo, const VertexArray& vao,
			const Shader& shader, GLenum mode = GL_FILL) const;

		void draw(const VertexBuffer& vbo, const VertexArray& vao,
			const IndexBuffer& ibo, const Shader& shader,
			GLenum mode = GL_FILL) const;

		void clear(GLfloat red = 0.0f, GLfloat green = 0.0f,
			GLfloat blue = 0.0f, GLfloat alpha = 0.0f) const;
	};
}
