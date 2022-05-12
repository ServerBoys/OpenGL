#include "IndexBuffer.h"

const void IndexBuffer::UnbindAll() {
	glBindBuffer(m_Type, 0);
}