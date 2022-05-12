#include "button.h"
namespace wp {
	Button::Button(std::string name, int width = 0, int height = 0)
			: name(name), size(width, height)
	{
		this->run = []() {};
	}

	void Button::draw() {
		if (ImGui::Button(name.c_str(), size)) {
			run();
		}
	}

	void Button::SetOnClick(void (*run)(void)) {
			this->run = run;
	}
} 