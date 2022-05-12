#include <glew.h>
#include <stb_image.h>

class Texture {
public:
	Texture(const char* path);
	~Texture();
	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
private:
	unsigned int m_RendererId;
	int m_Width, m_Height, m_BPP;
};