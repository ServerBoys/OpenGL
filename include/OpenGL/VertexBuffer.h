#pragma once
#include "Buffer.h"

template <typename T=float>
class VertexBuffer: public Buffer<T> {
private:
	static const unsigned int m_Type = GL_ARRAY_BUFFER;
public:
	VertexBuffer(uint64_t count, T* data): Buffer<T>(m_Type, count, data) {}
	const static void UnbindAll();
};