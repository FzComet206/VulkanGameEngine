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

		// takes window as constructor argument
		LveDevice lveDevice{lveWindow};

		LvePipeline lvePipeline{
			lveDevice,
			std::filesystem::current_path().string() + "\\vertex.vert.spv",
			std::filesystem::current_path().string() + "\\fragment.frag.spv",
			LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
			};
	};
}
