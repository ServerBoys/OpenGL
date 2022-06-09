#include "Window.h"

Window::Window(const char* title, int width, int height) {
	m_Title = title;
	m_Width = width;
	m_Height = height;

	WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	WindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

Window::~Window() {
	glfwDestroyWindow(m_Window);
}

bool Window::isValid() const {
	return m_Window;
}

bool Window::shouldClose() const {
	return glfwWindowShouldClose(m_Window);
}

void Window::MakeContextCurrent() const {
	glfwMakeContextCurrent(m_Window);
}

void Window::WindowHint(int hint, int value) const {
	glfwWindowHint(hint, value);
}

void Window::Terminate() {
	glfwTerminate();
}

void Window::SwapBuffers() const {
	glfwSwapBuffers(m_Window);
}

void Window::SetViewport() const {
	glViewport(0, 0, m_Width, m_Height);
}