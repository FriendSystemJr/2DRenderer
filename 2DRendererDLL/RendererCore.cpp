#include "RendererCore.h"

#include <vector> 

namespace Renderer {

	GLFWwindow* RendererCore::m_window = nullptr;
	Shader RendererCore::m_Shader;

	bool RendererCore::InitOpenGL(unsigned int width, unsigned int height, const char* windowName) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(width, height, windowName, NULL, NULL);

		//Check for error
		if (!m_window) {
			std::cout << "ERROR:RENDERER::CORE::FAILED_TO_CREATE_WINDOW!\n";
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);;

		//Init GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "ERROR:RENDERER::CORE::FAILED_TO_INIT_GLAD!\n";
		}

		// TODO: Change default color
		glViewport(0, 0, width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		return true;
	}

	//Callbacks
	void RendererCore::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	//Getter
	GLFWwindow* RendererCore::GetWindow()
	{
		return m_window;
	}

	Shader& RendererCore::GetShader() {
		return RendererCore::m_Shader;
	}

}