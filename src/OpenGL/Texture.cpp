#include "Texture.h"

Texture::Texture(const char* path)
	:m_RendererId(0), m_Width(0), m_Height(0), m_BPP(0)
{
	int width, height, BPP;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(path, &width, &height, &m_BPP, 4);
	glGenTextures(1, &m_RendererId);
	glBindTexture(GL_TEXTURE_2D, m_RendererId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	Unbind();
	if (data)
		stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RendererId);
}

void Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererId);
}

void Texture::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}