#pragma once
#include <array>

namespace Renderer {
	class Pixel {
	public:

		Pixel();

		// Getter
		bool IsSet();
		std::array<float, 4>& GetColor();

		// Setter
		void SetPixel(std::array<float, 4> color = { 1.0f, 1.0f, 1.0f, 1.0f });
		void UnsetPixel();

	private:
		bool m_isSet;
		std::array<float, 4> m_color;
	};
}