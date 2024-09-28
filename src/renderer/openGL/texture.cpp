#include "texture.h"

#include "glad/glad.h"
#include "stb_image.h"

#include <string>
#include <filesystem>
#include <iostream>

namespace Syrus
{
	Texture::Texture(const std::string& filePath) :m_ID(0), m_width(0),
		m_height(0), m_channels(0), m_filePath(filePath)
	{
		glGenTextures(1, &m_ID);
		bind();

		// Set texture wrap, min filter, and max filter settings.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Flip loaded textures on the y-axis to be right side up.
		stbi_set_flip_vertically_on_load(true);

		unsigned char* data = stbi_load(filePath.c_str(), &m_width, &m_height,
			&m_channels, 0);

		std::filesystem::path path = m_filePath;

		// Generate texture and mipmaps if data is valid.
		if (data && path.extension() == ".jpg")
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0,
				GL_RGB, GL_UNSIGNED_BYTE, data);

			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else if (data && path.extension() == ".png")
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0,
				GL_RGBA, GL_UNSIGNED_BYTE, data);

			glGenerateMipmap(GL_TEXTURE_2D);
			
		}
		else
		{
			std::cout << "Failed to load texture: \"" << m_filePath
				<< '"' << std::endl;
		}

		unbind();
		stbi_image_free(data);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_ID);
	}

	void Texture::bind(GLuint slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}

	void Texture::unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
