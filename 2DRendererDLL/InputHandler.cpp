#include <GLFW/glfw3.h>
#include "InputHandler.h"

namespace Renderer {
	int InputHandler::GetKey(GLFWwindow* window, int key) {
		return glfwGetKey(window, key);
	}
}
