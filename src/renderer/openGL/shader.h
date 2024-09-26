/**
 * This class represents a shader which consists of both a vertex shader and a
 * fragment shader. The vertex shader runs once per vertex and is responsible
 * for the various vertex attributes such as position, color, texture, etc. The
 * fragment shader is run once per pixel and is responsible for the final,
 * output color of each pixel.
 */
#pragma once

#include <glad/glad.h>

#include <string>

namespace Syrus
{
	class Shader
	{
	public:
		Shader(const std::string& vertexShaderFilePath,
			const std::string& fragmentShaderFilePath);

		~Shader();

		void use() const;

		void setUniformBool(const std::string& uniformName,
			GLboolean value) const;

		void setUniformFloat(const std::string& uniformName,
			GLfloat value) const;

		void setUniformInt(const std::string& uniformName, GLint value) const;

	private:
		GLuint m_ID;
	};
}
