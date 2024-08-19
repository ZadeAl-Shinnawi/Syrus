#pragma once

#include "openGL/vertexBuffer.h"
#include "openGL/vertexArray.h"
#include "openGL/shader.h"

#include <glad/glad.h>

namespace Syrus
{
	class Renderer
	{
	public:
		//Renderer();

		// Render?
		void draw(const VertexBuffer& vbo, const VertexArray& vao, const Shader& shader);
		void clear(GLfloat red = 0.0f, GLfloat green = 0.0f, GLfloat blue = 0.0f,
			GLfloat alpha = 0.0f) const;
	};
}
