/**
 * This class represents a texture object and all related functionality such
 * loading, specifying format, and various miscellaneous options.
 */
#pragma once

#include <glad/glad.h>

#include <string>

namespace Syrus
{
	class Texture
	{
	public:
		Texture(const std::string& filePath);
		~Texture();

		void bind(GLuint slot = 0) const;
		void unbind() const;
	private:
		GLuint m_ID;
		int m_width;
		int m_height;
		int m_channels;
		std::string m_filePath;
	};
}
