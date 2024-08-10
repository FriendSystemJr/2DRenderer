#include "Grid.h"
#include "Shader.h"
#include <iostream>

namespace Renderer {

	Grid::Grid(unsigned int x, unsigned int y) {
		m_grid = std::vector<std::vector<bool>>(x, std::vector<bool>(y, false));
		std::cout << "Init grid\n";

		Grid::m_sizeX = x;
		Grid::m_sizeY = y;

		Grid::m_VAO = 0;
		Grid::m_VBO = 0;

		Grid::m_pixelWidth = 2.0f / x;
		Grid::m_pixelHeight = 2.0f / y;
	}

	Grid CreateGrid(unsigned int x, unsigned int y) {
		return Grid(x, y);
	}

	void Grid::SetPixel(unsigned int x, unsigned int y) {
		if (x >= this->m_sizeX || y >= this->m_sizeY) {
			std::cout << "Value too big for grid size!";
			return;
		} else if (x >= 0 && x < this->m_sizeX && y >= 0 && y < this->m_sizeY) {
			this->m_grid[x][y] = true;
			return;
		}

		if (this->m_grid[x][y])
			return;
	}

	//Getter
	float Grid::GetPixelWidth() const{
		return Grid::m_pixelWidth;
	}

	float Grid::GetPixelHeight() const {
		return Grid::m_pixelHeight;
	}

	unsigned int Grid::GetSizeX() const {
		return Grid::m_sizeX;
	}

	unsigned int Grid::GetSizeY() const {
		return Grid::m_sizeY;
	}

	std::vector<std::vector<bool>>& Grid::GetGrid() {
		return Grid::m_grid;
	}

	std::vector<float>& Grid::GetVertices() {
		return Grid::m_vertices;
	}

	unsigned int& Grid::GetVAO() {
		return Grid::m_VAO;
	}

	unsigned int& Grid::GetVBO() {
		return Grid::m_VBO;
	}

}