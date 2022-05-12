#pragma once

#include <GL/glew.h>
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray {
private:
	unsigned int m_RendererID;
public:
	VertexArray();
	~VertexArray();
	template <typename T>
	void AddBuffer(const VertexBuffer<T>& vb, const VertexBufferLayout& layout) const {
		Bind();
		vb.Bind();
		AddLayout(layout);
	}
	void AddLayout(const VertexBufferLayout& layout) const;
	void Bind() const;
	void Unbind() const;
	static void UnbindAll();
};