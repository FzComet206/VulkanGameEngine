#pragma once

#include "lve_window.hpp"

namespace lve {
	class FirstApp {

	public:
		static constexpr int WIDTH = 1920;
		static constexpr int HEIGHT = 1080;

		void run();

	private:
		LveWindow lveWindow{
			WIDTH,
			HEIGHT,
			"Hi"
		};
	};
}
