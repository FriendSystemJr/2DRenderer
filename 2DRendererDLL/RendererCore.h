#pragma once
#include "Shader.h"

#include <GLFW/glfw3.h>
#include <vector>

namespace Renderer {

class RendererCore {
public:

	// Functions
	static bool InitOpenGL(unsigned int width, unsigned int height, const char* windowName);
	static void CleanupOpenGL(unsigned int& VBO, unsigned int& VAO);
	static void SetInputCallback()

	// Callbacks
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	// Getter
	static GLFWwindow* GetWindow();

private:

	// Variables

	static GLFWwindow* m_window;

	};
}