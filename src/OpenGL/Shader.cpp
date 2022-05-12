#include "Shader.h"

Shader::Shader(const char* name) {
	m_RendererID = glCreateProgram();
	const char* vertexShader = LoadShader(name, GL_VERTEX_SHADER);
	const char* fragmentShader = LoadShader(name, GL_FRAGMENT_SHADER);
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(m_RendererID, vs);
	glAttachShader(m_RendererID, fs);
	glLinkProgram(m_RendererID);
	glValidateProgram(m_RendererID);

	glDeleteShader(vs);
	glDeleteShader(fs);
	delete[] vertexShader;
	delete[] fragmentShader;
}

Shader::~Shader() {
	glDeleteProgram(m_RendererID);
}

const char* Shader::LoadShader(std::string filename, GLenum type) const {
	std::string filepath = "./res/shaders/"+ filename;
	if (type == GL_VERTEX_SHADER)
		filepath += "Vertex.glsl";
	else if (type == GL_FRAGMENT_SHADER)
		filepath += "Fragment.glsl";
	else
		return nullptr;
	std::ifstream filestream;
	unsigned int length;
	filestream.open(filepath);
	filestream.seekg(0, std::ios::end);
	length = (unsigned int)filestream.tellg() + 1;
	filestream.seekg(0, std::ios::beg);
	char* buffer = new char[length];
	buffer[length - 1] = '\0';
	filestream.read(buffer, length);
	filestream.close();
	return buffer;
}

unsigned int Shader::CompileShader(unsigned int type, const char* source) const {
	unsigned int id = glCreateShader(type);
	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << 
			(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << 
			" shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

void Shader::Bind() const {
	glUseProgram(m_RendererID);
}

void Shader::Unbind() const {
	glUseProgram(0);
}

void Shader::UnbindAll() {
	glUseProgram(0);
}

int Shader::getUniformLocation(const char* name) {
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];
	int location = glGetUniformLocation(m_RendererID, name);
	if (location == -1)
		std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
	m_UniformLocationCache[name] = location;
	return location;
}

void Shader::SetUniform4f(const char* name, float v0, float v1, float v2, float v3){
	glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}