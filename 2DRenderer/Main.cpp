#include "RenderAPI.h"

int main() {

	Renderer::Init(800, 800, "Ein Fenster!");

	Renderer::Shader shader("vertex.txt", "fragment.txt");

	Renderer::Grid grid = Renderer::CreateGrid(32, 32);

	// TODO: Template BufferManager
	Renderer::BufferManager buffer(grid);

	buffer.SetGridStandard();

	grid.SetPixel(0, 0, {1.0f, 0.0f, 0.0f, 1.0f});
	grid.SetPixel(1, 1);
	grid.SetPixel(2, 2, { 0.831f, 0.082f, 0.961f, 1.0f });

	grid.SetPixel(31, 31, { 0.369f, 0.929f, 0.859f, 1.0f });

	grid.SetPixel(0, 31, { 1.0f, 0.0f, 0.0f, 1.0f });

	/*for (int i = 0; i < 99; ++i) {
		for (int j = 0; j < 99; ++j) {
			if ((i % 2 == 0) && (j % 2 == 0)) {
				grid.SetPixel(i, j, {0.686f, 0.541f, 0.89f, 1.0f});
					continue;
			}
			if ((i % 3 == 0) && (j % 3 == 0)) {
				grid.SetPixel(i, j, { 0.761f, 0.902f, 0.49f, 1.0f });
					continue;
			} if ((i % 5 == 0) && (j % 3 == 0)) {
				grid.SetPixel(i, j, { 0.941f, 0.714f, 0.341f, 1.0f });
				continue;
			} if ((i % 7 == 0) && (j % 3 == 0)) {
				grid.SetPixel(i, j, { 0.435f, 0.847f, 0.941f, 1.0f });
				continue;
			} if ((i % 11 == 0) && (j % 3 == 0)) {
				grid.SetPixel(i, j, { 0.f, 0.f, 1.f, 1.0f });
				continue;
			} if ((i % 13 == 0) && (j % 3 == 0)) {
				grid.SetPixel(i, j, { 1.f, 0.f, 0.f, 1.0f });
				continue;
			} if ((i % 17 == 0) && (j % 3 == 0)) {
				grid.SetPixel(i, j, { 1.f, 0.f, 0.384f, 1.0f });
				continue;
			}

			grid.SetPixel(i, j, { 0.753f, 0.859f, 0.201f, 1.0f });
		}
	}*/

	while (!Renderer::windowShouldClose()) {
		// TODO: Properly integrate shader into grid
		//Renderer::processInput(window);
		Renderer::RenderGrid(grid, shader);
		
	}

	char a = 'a';
	char A = 'A';

	std::cout << (int)a << ", " << (int)A << "\n";
	Renderer::Cleanup(grid.GetVBO(), grid.GetVAO());
}