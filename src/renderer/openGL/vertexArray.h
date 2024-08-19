#pragma once

#include <initializer_list>

namespace Syrus
{
	class VertexArray
	{
	public:
		VertexArray(const std::initializer_list<unsigned int>& vertexAttributes);
		~VertexArray();

		void bind() const;
		void unbind() const;

		// add mem var, so don't have to calc every time.
		inline unsigned int getAttributeSum() const { return m_numAttributeFloats; }

	private:
		unsigned int m_ID;
		unsigned int m_numAttributeFloats;
		std::initializer_list<unsigned int> m_vertexAttributes;
	};
}
