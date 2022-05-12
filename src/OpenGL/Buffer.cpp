#include "Buffer.h"

template <typename T>
Buffer<T>::Buffer(unsigned int type, uint64_t count, T* data) {
	m_Type = type;
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(m_Type, m_RendererID);
	glBufferData(m_Type, count * sizeof(T), data, GL_STATIC_DRAW);
}

template <typename T>
Buffer<T>::~Buffer() {
	glDeleteBuffers(1, &m_RendererID);
}

template <typename T>
void Buffer<T>::Bind() const {
	glBindBuffer(m_Type, m_RendererID);
}

template <typename T>
void Buffer<T>::Unbind() const {
	glBindBuffer(m_Type, 0);
}

template class Buffer<float>;
template class Buffer<int>;
template class Buffer<unsigned int>;
template class Buffer<unsigned char>;

// template <typename T>
// DataType Buffer<T>::GetDataType() const {
// 	if (T == float) {
// 		return FLOAT;
// 	}
// 	else if (T == int) {
// 		return INT;
// 	}
// 	else if (T == unsigned int) {
// 		return UNSIGNED_INT;
// 	}
// 	else if (T == unsigned char) {
// 		return UNSIGNED_BYTE;
// 	}
// }