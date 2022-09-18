#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve {
	class LveWindow {

	public:
		// constructor
		LveWindow(int w, int h, std::string name);
		// destructor
		~LveWindow();

		// wtf is this
		LveWindow(const LveWindow&) = delete;
		LveWindow& operator=(const LveWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }

	private:

		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow *window;
	};
}
