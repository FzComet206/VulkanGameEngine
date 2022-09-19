#pragma once

#include "lve_window.hpp"
#include "pipeline.hpp"

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
			"Hi Vulkan"
		};
		LvePipeline lvePipeline{"src/shaders/vertex.vert.spv", "src/shaders/fragment.frag.spv"};
	};
}
