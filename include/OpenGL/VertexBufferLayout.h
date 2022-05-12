#pragma once

#include <vector>
#include "GL/glew.h"

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	bool normalized;

	static unsigned int GetSizeOfType(unsigned int type);
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public:
	VertexBufferLayout();
	template <typename T>
	void Push(unsigned int count);
	inline unsigned int GetStride() const { return m_Stride; }
	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
};
	
