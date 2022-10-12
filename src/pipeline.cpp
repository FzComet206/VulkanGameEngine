#include "pipeline.hpp"
#include <fstream>
#include <stdexcept>

namespace lve {

    LvePipeline::LvePipeline(
            LveDevice &device,
            const std::string& vertFilepath, 
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo) : lveDevice(device) {

            createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
    }


    std::vector<char> LvePipeline::readFile(const std::string& filepath){

        // ate -- we seek the end of the file
        std::ifstream file(filepath, std::ios::ate | std::ios::binary);
        if (!file.is_open()){
            throw std::runtime_error("fail to open file: " + filepath);
        }

        // ate to reach end of file, tellg to tell position, which is file size
        size_t filesize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(filesize);

        // so that we can read file
        file.seekg(0);
        file.read(buffer.data(), filesize);
        file.close();
        return buffer;
    }
    
    void LvePipeline::createGraphicsPipeline(
        const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo){
            auto vertCode = readFile(vertFilepath);
            auto fragCode = readFile(fragFilepath);

            std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
            std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }

    void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule){
        // pattern in vulkan: create a struct and call a function with pointer to it
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        // cast char arr to uint32 type
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS){
            throw std::runtime_error("failed to create shader module");
        }
    }

    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};
    }

}