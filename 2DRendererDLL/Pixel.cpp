#include "Pixel.h"

namespace Renderer {
	Pixel::Pixel() {
		Pixel::m_isSet = false;
		Pixel::m_color.fill(1.0f);
	}

	// Getter
	bool Pixel::IsSet() {
		return Pixel::m_isSet;
	}

	std::array<float, 4>& Pixel::GetColor() {
		return Pixel::m_color;
	}

	// Setter
	void Pixel::SetPixel(std::array<float, 4> color) {
		Pixel::m_isSet = true;
		Pixel::m_color = color;
	}

	void Pixel::UnsetPixel() {
		Pixel::m_isSet = false;
	}

	void Pixel::SetColor(std::array<float, 4> color) {
		m_color = color;
	}

}