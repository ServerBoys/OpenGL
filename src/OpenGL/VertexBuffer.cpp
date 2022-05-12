#include "VertexBuffer.h"

template <typename T>
const void VertexBuffer<T>::UnbindAll() {
	glBindBuffer(m_Type, 0);
}

template class VertexBuffer<float>;