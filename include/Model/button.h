#pragma once
#include "imgui.h"
#include <iostream>
namespace wp {
	class Button {
	private:
		std::string name;
		ImVec2 size;
		void (*run) (void);
	public:
		Button(std::string, int, int);
		void draw();
		void SetOnClick(void (*run)(void));
	};
}