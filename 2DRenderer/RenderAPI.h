#include "Shader.h"
#include "Grid.h"
#include "BufferManager.h"

namespace Renderer {
	
	extern "C" {
		__declspec(dllimport) void Init(unsigned int width, unsigned int height, const char* windowName);
		__declspec(dllimport) bool windowShouldClose();
		__declspec(dllimport) void RenderGrid(Grid& grid, Shader& shader);
	}
}