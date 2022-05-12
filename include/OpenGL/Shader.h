#pragma once

#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <unordered_map>


class Shader {
private:
	unsigned int m_RendererID;
	std::unordered_map<const char*, int> m_UniformLocationCache;
	
public:
	Shader(const char* name);
	~Shader();
	const char* LoadShader(std::string filename, GLenum type) const;
	unsigned int CompileShader(unsigned int type, const char* source) const;
	void Bind() const;
	void Unbind() const;
	int getUniformLocation(const char* name);
	void SetUniform4f(const char* name, float v0, float v1, float v2, float v3);
	static void UnbindAll();
};