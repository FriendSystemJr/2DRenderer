#include "RenderAPI.h"

int main() {

	Renderer::Init(800, 400, "First window!");

	Renderer::Shader shader("vertex.txt", "fragment.txt");

	Renderer::Grid grid = Renderer::CreateGrid(64, 32);

	Renderer::BufferManager buffer(grid);

	buffer.Bind();
	buffer.SetBufferData(grid.GetVertices().size() * sizeof(float), grid.GetVertices().data(), GL_DYNAMIC_DRAW);
	buffer.SetVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	buffer.SetVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2*sizeof(float)));

	grid.SetPixel(1, 1);
	grid.SetPixel(0, 0, {1.0f, 0.0f, 0.0f, 1.0f});

	while (!Renderer::windowShouldClose()) {
		// TODO: Properly integrate shader into grid
		Renderer::RenderGrid(grid, shader);
	}

}