#include "lve_window.hpp"

namespace lve {
	LveWindow::LveWindow(int w, int h, std::string name) : width(w), height(h), windowName(name){
		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::initWindow() {
		glfwInit();
		// tell glfw to not create opengl context
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		// tell glfw to disable our window from being resized during creation, because we will resize windows in another way later
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}