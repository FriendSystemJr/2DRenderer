
#include "RenderAPI.h"
#include "RendererCore.h"
#include "Grid.h"

namespace Renderer {
	extern "C" {

		// Function for catching OpenGL errors
		void checkGLError(const char* point) {
			GLenum err;
			while ((err = glGetError()) != GL_NO_ERROR) {
				switch (err) {
				case GL_INVALID_ENUM:
					std::cerr << point << ": GL_INVALID_ENUM" << std::endl;
					break;
				case GL_INVALID_VALUE:
					std::cerr << point << ":GL_INVALID_VALUE" << std::endl;
					break;
				case GL_INVALID_OPERATION:
					std::cerr << point << ":GL_INVALID_OPERATION" << std::endl;
					break;
				case GL_OUT_OF_MEMORY:
					std::cerr << point << ":GL_OUT_OF_MEMORY" << std::endl;
					break;
				case GL_INVALID_FRAMEBUFFER_OPERATION:
					std::cerr << point << ":GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl;
					break;
				default:
					std::cerr << point << ":Unknown error (" << err << ")" << std::endl;
					break;
				}
			}
		}

		void Init(unsigned int width, unsigned int height, const char* windowName) {
			Renderer::RendererCore::InitOpenGL(width, height, windowName);
			std::cout << "Created window! :)\n";
		}

		bool windowShouldClose() {
			return glfwWindowShouldClose(Renderer::RendererCore::GetWindow());
		}

		void RenderGrid(Grid& grid, Shader& shader) {
			// Clear screen from initial colors
			glClear(GL_COLOR_BUFFER_BIT);
			// iterate over grid to push points to render in vector
			for (int i = 0; i < grid.GetSizeX(); ++i) {
				for (int j = 0; j < grid.GetSizeY(); ++j) {
					if (grid.GetGrid()[i][j]) {

						float x = -1.0f + i * grid.GetPixelWidth();
						float y = -1.0f + j * grid.GetPixelHeight();

						// Draw two triangles for 1 pixel
						// TODO: Optimize with EBO

						// Push back the first triangle
						grid.GetVertices().push_back(x);
						grid.GetVertices().push_back(y);

						grid.GetVertices().push_back(x + grid.GetPixelWidth());
						grid.GetVertices().push_back(y);

						grid.GetVertices().push_back(x);
						grid.GetVertices().push_back(y + grid.GetPixelHeight());

						// Push back the second triangle
						grid.GetVertices().push_back(x);
						grid.GetVertices().push_back(y + grid.GetPixelHeight());

						grid.GetVertices().push_back(x + grid.GetPixelWidth());
						grid.GetVertices().push_back(y);

						grid.GetVertices().push_back(x + grid.GetPixelWidth());
						grid.GetVertices().push_back(y + grid.GetPixelHeight());
					}
				}
			}

			// Bind Buffer and empty it because of dynamic array size (reallocation)
			glBindBuffer(GL_ARRAY_BUFFER, grid.GetVBO());
			glBufferData(GL_ARRAY_BUFFER, grid.GetVertices().size() * sizeof(float), NULL, GL_DYNAMIC_DRAW);

			shader.use();

			// Buffer new data and then unbind buffer
			glBufferSubData(GL_ARRAY_BUFFER, 0, grid.GetVertices().size() * sizeof(float), grid.GetVertices().data());
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			
			// Bind vao for drawing
			glBindVertexArray(grid.GetVAO());
			glDrawArrays(GL_TRIANGLES, 0, grid.GetVertices().size() / 2);

			grid.GetVertices().clear();

			// TODO: Maybe also rework window usage
			glfwSwapBuffers(RendererCore::GetWindow());
			glfwPollEvents();

		}

	}
}