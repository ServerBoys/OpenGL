#pragma once

#include "Buffer.h"
class IndexBuffer: public Buffer<unsigned int> {
private:
	static const unsigned int m_Type = GL_ELEMENT_ARRAY_BUFFER;
	uint64_t m_Count;
public:
	IndexBuffer(uint64_t count, unsigned int* data): Buffer<unsigned int>(m_Type, count, data) {
		m_Count = count;
	}
	const uint64_t getCount() const { return m_Count; }
	const static void UnbindAll();
};