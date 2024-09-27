#include "renderer.h"
#include "openGL/vertexBuffer.h"
#include "openGL/vertexArray.h"
#include "openGL/indexBuffer.h"

#include "glad/glad.h"

namespace Syrus
{
	void Renderer::draw(const VertexBuffer& vbo, const VertexArray& vao,
		const Shader& shader, GLenum mode) const
	{
		glPolygonMode(GL_FRONT_AND_BACK, mode);

		vbo.bind();
		vao.bind();
		shader.use();

		glDrawArrays(GL_TRIANGLES, 0,
			vbo.getTotalFloats() / vao.getAttributeSum());
	}

	void Renderer::draw(const VertexBuffer& vbo, const VertexArray& vao,
		const IndexBuffer& ibo, const Shader& shader, GLenum mode) const
	{
		glPolygonMode(GL_FRONT_AND_BACK, mode);

		vbo.bind();
		vao.bind();
		ibo.bind();
		shader.use();

		glDrawElements(GL_TRIANGLES, ibo.getIndexCount(), GL_UNSIGNED_INT,
			nullptr);
	}

	void Renderer::clear(GLfloat red, GLfloat green, GLfloat blue,
		GLfloat alpha) const
	{
		glClearColor(red, green, blue, alpha);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}
