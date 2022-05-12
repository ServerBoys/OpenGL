#include "VertexBufferLayout.h"

unsigned int VertexBufferElement::GetSizeOfType(unsigned int type) {
	switch (type) {
		case GL_FLOAT:
			return sizeof(float);
		case GL_UNSIGNED_INT:
			return sizeof(unsigned int);
		case GL_UNSIGNED_BYTE:
			return sizeof(unsigned char);
		case GL_INT:
			return sizeof(int);
	}
	return 0;
}

VertexBufferLayout::VertexBufferLayout()
	: m_Stride(0) {}

template <>
void VertexBufferLayout::Push<float>(unsigned int count) {
	m_Elements.push_back({ GL_FLOAT, count, false });
	m_Stride += count * sizeof(float);
}

template <>
void VertexBufferLayout::Push<int>(unsigned int count) {
	m_Elements.push_back({ GL_INT, count, false });
	m_Stride += count * sizeof(int);
}

template <>
void VertexBufferLayout::Push<unsigned int>(unsigned int count) {
	m_Elements.push_back({ GL_UNSIGNED_INT, count, false });
	m_Stride += count * sizeof(unsigned int);
}

template <>
void VertexBufferLayout::Push<unsigned char>(unsigned int count) {
	m_Elements.push_back({ GL_UNSIGNED_BYTE, count, true });
	m_Stride += count * sizeof(unsigned char);
}