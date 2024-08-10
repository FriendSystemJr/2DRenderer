#pragma once
#include "Shader.h"

#include <GLFW/glfw3.h>
#include <vector>

namespace Renderer {

class RendererCore {
public:

	//Functions
	static bool InitOpenGL(unsigned int width, unsigned int height, const char* windowName);

	//Callbacks
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	//Getter
	static GLFWwindow* GetWindow();
	static Shader& GetShader();

private:

	//Variables
	static Shader m_Shader;

	//static int m_gridSize[2]; //x and y size of the grid

	static GLFWwindow* m_window;

	};
}