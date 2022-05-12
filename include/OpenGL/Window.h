#pragma once

#include <glfw3.h>
#include <iostream>
class Window {
private:
	GLFWwindow* m_Window;
	const char* m_Title;
	int m_Width, m_Height;

public:
	Window(const char* title, int width, int height);
	~Window();
	bool isValid() const;
	bool shouldClose() const;
	void MakeContextCurrent() const;
	void WindowHint(int hint, int value) const;
	void SwapBuffers() const;
	void SetViewport() const;
	inline const float scaleX(float x) const { return 2 * x / m_Width - 1.0f; };
	inline const float scaleY(float y) const { return 2 * y / m_Height - 1.0f; };
	
	inline const int getWidth() const { return m_Width; }
	inline const int getHeight() const { return m_Height; }
};