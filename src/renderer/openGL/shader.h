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
		/**
		 * @brief This constructor reads in both a vertex shader source file
		 * and a fragment shader source file - each written in GLSL. It then
		 * creates both a vertex shader object and fragment shader object,
		 * generates a unique ID for each of them, compiles them, and checks
		 * for compilation errors. Both shaders are then attached and linked
		 * into a shader program which is also given a unique ID. Finally, both
		 * the vertex shader and fragment shader are each deleted.
		 *
		 * @param vertexShaderFilePath The vertex shader GLSL shader file path.
		 * @param fragmentShaderFilePath The fragment shader GLSL shader file
		 * path.
		 */
		Shader(const std::string& vertexShaderFilePath,
			const std::string& fragmentShaderFilePath);

		/**
		 * This destructor deletes the shader program and allows the unique ID
		 * to be used again.
		 */
		~Shader();

		/**
		 * @brief Installs the shader program as part of the current rendering
		 * state.
		 */
		void use() const;

		/**
		 * @brief Specifies the value of a uniform bool variable for the
		 * current shader program.
		 *
		 * @param uniformName The name of the uniform.
		 * @param value The value of the uniform.
		 */
		void setUniformBool(const std::string& uniformName,
			GLboolean value) const;

		/**
		 * @brief Specifies the value of a uniform float variable for the
		 * current shader program.
		 *
		 * @param uniformName The name of the uniform.
		 * @param value The value of the uniform.
		 */
		void setUniformFloat(const std::string& uniformName,
			GLfloat value) const;

		/**
		 * @brief Specifies the value of a uniform int variable for the current
		 * shader program.
		 *
		 * @param uniformName The name of the uniform.
		 * @param value The value of the uniform.
		 */
		void setUniformInt(const std::string& uniformName, GLint value) const;

	private:
		/**
		 * @brief Represents the unique, OpenGL ID for the shader.
		 */
		GLuint m_ID;
	};
}
