/**
 * This class represents a vertex array which represents the attribute layout
 * of data in a vertex buffer. This includes the total number of vertex
 * attributes as well as the total number of floats per vertex attribute.
 */
#pragma once

#include <initializer_list>

namespace Syrus
{
	class VertexArray
	{
	public:
		VertexArray(const std::initializer_list<unsigned int>&
			vertexAttributes);

		~VertexArray();

		void bind() const;
		void unbind() const;

		// Returns the total number of floats in all attributes combined.
		inline unsigned int getAttributeSum() const
		{
			return m_numAttributeFloats;
		}

	private:
		unsigned int m_ID;

		// The total number of floats in all attributes combined.
		unsigned int m_numAttributeFloats;
		std::initializer_list<unsigned int> m_vertexAttributes;
	};
}
