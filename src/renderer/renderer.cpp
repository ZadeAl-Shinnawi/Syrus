#include "renderer.h"

#include "glad/glad.h"

namespace Syrus
{
	void Renderer::draw(const VertexBuffer& vbo, const VertexArray& vao, const Shader& shader)
	{
		glDrawArrays(GL_TRIANGLES, 0, vbo.getTotalFloats() / vao.getAttributeSum());
	}

	void Renderer::clear(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) const
	{
		glClearColor(red, green, blue, alpha);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
