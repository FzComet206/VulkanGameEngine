#include "pipeline.hpp"
#include <fstream>
#include <stdexcept>

namespace lve {

    LvePipeline::LvePipeline(const std::string& vertFilepath, const std::string& fragFilepath){
        createGraphicsPipeline(vertFilepath, fragFilepath);
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
        const std::string& vertFilepath, const std::string& fragFilepath){
            auto vertCode = readFile(vertFilepath);
            auto fragCode = readFile(fragFilepath);

            std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
            std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }
}