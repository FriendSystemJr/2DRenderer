#include "Grid.h"
#include <iostream>

namespace Renderer {

	Grid::Grid(unsigned int x, unsigned int y) {
		//Initialize grid with given size
		m_grid = std::vector<std::vector<Pixel>>(x, std::vector<Pixel>(y, Pixel()));
		std::cout << "Init grid\n";

		// Set size of grid
		Grid::m_sizeX = x;
		Grid::m_sizeY = y;

		// Init VAO/VBO
		Grid::m_VAO = 0;
		Grid::m_VBO = 0;

		// Calculate offset for vertex pos
		Grid::m_pixelWidth = 2.0f / x;
		Grid::m_pixelHeight = 2.0f / y;
	}

	Grid CreateGrid(unsigned int x, unsigned int y) {
		return Grid(x, y);
	}

	void Grid::SetPixel(unsigned int x, unsigned int y, std::array<float, 4> color) {
		// Check if specified values are in the grid and atleast 0
		if ((x >= this->m_sizeX || y >= this->m_sizeY) && (x >= 0 && y >= 0)) {
			std::cout << "Value too big for grid size!";
			return;

			//Check if pixel is already set
		} else if (this->m_grid[x][y].IsSet()) {
			return;
		}
			
		//Set pixel to true
		this->m_grid[x][y].SetPixel(color);
		
	}

	// TODO reset color when unsetting pixel
	void Grid::UnsetPixel(unsigned int x, unsigned int y) {
		// Check if specified values are in the grid and atleast 0
		if ((x >= this->m_sizeX || y >= this->m_sizeY) && (x >= 0 && y >= 0)) {
			std::cout << "Value too big for grid size!";
			return;
		}

		if (this->m_grid[x][y].IsSet() == false)
			return;

		this->m_grid[x][y].UnsetPixel();

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

	std::vector<std::vector<Pixel>>& Grid::GetGrid() {
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