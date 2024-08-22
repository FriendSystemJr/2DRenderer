#include "RenderAPI.h"

void HandleInput(GLFWwindow* window, Renderer::Grid& grid);

int main() {

	Renderer::Init(800, 800, "Ein Fenster!");

	Renderer::Shader shader("vertex.txt", "fragment.txt");

	Renderer::Grid grid = Renderer::CreateGrid(32, 32);

	// TODO: Template BufferManager
	Renderer::BufferManager buffer(grid);

	buffer.SetGridStandard();

	/*grid.SetPixel(0, 0, {1.0f, 0.0f, 0.0f, 1.0f});
	grid.SetPixel(1, 1);
	grid.SetPixel(2, 2, { 0.831f, 0.082f, 0.961f, 1.0f });

	grid.SetPixel(31, 31, { 0.369f, 0.929f, 0.859f, 1.0f });

	grid.SetPixel(0, 31, { 1.0f, 0.0f, 0.0f, 1.0f });*/

	while (!Renderer::windowShouldClose()) {
		// TODO: Properly integrate shader into grid
		//Renderer::processInput(window);
		HandleInput((GLFWwindow*)Renderer::GetRenderWindow(), grid);
		Renderer::RenderGrid(grid, shader);
		
	}
	Renderer::Cleanup(grid.GetVBO(), grid.GetVAO());
}

void HandleInput(GLFWwindow* window, Renderer::Grid& grid) {
	if (Renderer::InputHandler::GetKey(window, Renderer::InputHandler::KeyCode::KEY_A) == Renderer::InputHandler::KEY_PRESSED) {
		if (!grid.IsSet(0, 0)) {
			grid.SetPixel(0, 0);
		}
	}

	if (Renderer::InputHandler::GetKey(window, Renderer::InputHandler::KeyCode::KEY_S) == Renderer::InputHandler::KEY_PRESSED) {
		if (grid.IsSet(0, 0)) {
			grid.UnsetPixel(0, 0);
		}
	}

}