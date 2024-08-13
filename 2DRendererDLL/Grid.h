#pragma once
#include <vector>

#include "Shader.h"
#include "Pixel.h"

namespace Renderer {

class __declspec(dllexport) Grid {
	
public:
	
	// Getter
	float GetPixelWidth() const;
	float GetPixelHeight() const;

	void SetPixel(unsigned int x, unsigned int y);
	void UnsetPixel(unsigned int x, unsigned int y);

	unsigned int GetSizeX() const;
	unsigned int GetSizeY() const;

	unsigned int& GetVAO();
	unsigned int& GetVBO();

	std::vector<std::vector<Pixel>>& GetGrid();
	std::vector<float>& GetVertices();

private:

	// Make constructor private so that it can only be created via method
	Grid() = delete;
	Grid(unsigned int x, unsigned int y);

	// Friend function so that it can access the constructor
	friend __declspec(dllexport) Grid CreateGrid(unsigned int x, unsigned int y);

	// Variables

	//std::vector<std::vector<bool>> m_grid;
	std::vector<std::vector<Pixel>> m_grid;
	std::vector<float> m_vertices;

	// Size of grid
	unsigned int m_sizeX;
	unsigned int m_sizeY;

	float m_pixelWidth;
	float m_pixelHeight;

	unsigned int m_VAO, m_VBO;
	
	};

	Grid __declspec(dllexport) CreateGrid(unsigned int x, unsigned int y);

}