#include "includes.h"
#include <time.h>
int main() {

    if (!glfwInit())
		return -1;

	{
		Window window("Hello World", 800, 600);
		if (!window.isValid())
		{
			window.Terminate();
			return -1;
		}
		window.MakeContextCurrent();
		if (glewInit() != GLEW_OK)
			std::cout << "Failed to initialize GLEW" << std::endl;
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		float vertex = window.scaleX(500);
		float vertex2 = window.scaleY(450);
		float vertex3 = window.scaleX(300);
		float vertex4 = window.scaleY(250);

		float vertices[] = {
			vertex3, vertex4,
			vertex, vertex4,
			vertex,  vertex2,
			vertex3,  vertex2
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		VertexBuffer vb(4*2, vertices);
		VertexBufferLayout layout;
		layout.Push<float>(2);

		VertexArray va;
		va.AddBuffer(vb, layout);

		IndexBuffer ib(6, indices);

		Shader shader("Basic");
		Renderer renderer;
		IndexBuffer::UnbindAll();
		VertexArray::UnbindAll();
		Shader::UnbindAll();


		while (!window.shouldClose()) {
			glfwPollEvents();
			renderer.Clear();

			shader.Bind();
			shader.SetUniform4f("u_Color", 1.0f, 0.0f, 0.0f, 1.0f);

			renderer.Draw(va, ib, shader);
			
			window.SetViewport();
			window.SwapBuffers();
		}
	}
    glfwTerminate();

    return 0;

}