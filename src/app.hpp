#pragma once
#include <filesystem>

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
		LvePipeline lvePipeline{
			std::filesystem::current_path().string() + "\\vertex.vert.spv",
			std::filesystem::current_path().string() + "\\fragment.frag.spv",
			};
	};
}
