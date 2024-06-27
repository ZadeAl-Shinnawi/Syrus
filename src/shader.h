#pragma once

#include <string>

class Shader
{
public:
	Shader(const std::string& vertexShaderFilePath,
		const std::string& fragmentShaderFilePath);
	~Shader();

	void use() const;
	void unbind() const;

	// Uniforms...

private:
	unsigned int m_ID;
};
