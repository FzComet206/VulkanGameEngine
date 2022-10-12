#pragma once
#include <iostream>
#include <vector>

#include "lve_device.hpp"

namespace lve {

    struct PipelineConfigInfo {
        
    };

    class LvePipeline{
        // pipeline class is responsible for managing the lifetime of these resoureces

        public:
        LvePipeline(
            LveDevice &device,
            const std::string& vertFilepath, 
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);
        ~LvePipeline() {};

        // delete or copy constructors
        LvePipeline(const LvePipeline&) = delete;
        void operator = (const LvePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

        private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(
            const std::string& vertFilepath, 
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);

        // shaderModule is a pointer to a pointer
        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        // reference type member variable could be memory unsafe if device is relased before the pipeline
        // use here because device will implicitly outlive any instances of the containing class depend on it
        // this type of relationship is called aggregation
        LveDevice& lveDevice;
        // this is the handle to vulkan pipeline object
        VkPipeline graphicsPipeline;
        // shader modules, pointers
        VkShaderModule vertModule;
        VkShaderModule fragModule;
    };
};