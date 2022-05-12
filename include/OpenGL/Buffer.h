#pragma once

#include <GL/glew.h>

template <typename T=void>
class Buffer {
private:
	unsigned int m_RendererID;
	unsigned int m_Type;
public:
	Buffer(unsigned int type, uint64_t count, T* data);
	~Buffer();
	void Bind() const;
	void Unbind() const;
};