#include "RenderAPI.h"

int main() {

	Renderer::Init(800, 800, "Ein Fenster!");

	Renderer::Shader shader("vertex.txt", "fragment.txt");

	Renderer::Grid grid = Renderer::CreateGrid(32, 32);

	// TODO: Template BufferManager
	Renderer::BufferManager buffer(grid);

	buffer.SetGridStandard();

	grid.SetPixel(0, 0, { 1.0f, 0.0f, 0.0f, 1.0f });
	grid.SetPixel(1, 1);
	grid.SetPixel(2, 2, { 0.831f, 0.082f, 0.961f, 1.0f });

	while (!Renderer::windowShouldClose()) {
		// TODO: Properly integrate shader into grid
		Renderer::RenderGrid(grid, shader);
	}

}