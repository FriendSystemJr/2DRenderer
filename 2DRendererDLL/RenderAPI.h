#pragma once
#include "Grid.h"

namespace Renderer {
	extern "C" {
		__declspec(dllexport) void Init(unsigned int width, unsigned int height, const char* windowName);
		__declspec(dllexport) bool windowShouldClose();
		__declspec(dllexport) void RenderGrid(Grid& grid, Shader& shader);
		__declspec(dllexport) void Cleanup(unsigned int& VBO, unsigned int& VAO);
		__declspec(dllexport) void* GetRenderWindow();
		__declspec(dllexport) float GetDeltaTime();
	}
}