#include "../include/MapLoader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

bool MapLoader::loadCityMap(const std::string& filepath, GraphEngine& engine) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "[Error] Failed to open map data: " << filepath << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string source, destination, weightStr;

        if (std::getline(ss, source, ',') &&
            std::getline(ss, destination, ',') &&
            std::getline(ss, weightStr, ',')) {
            
            try {
                int weight = std::stoi(weightStr);
                engine.addEdge(source, destination, weight);
            } catch (const std::exception&) {
                std::cerr << "[Warning] Invalid weight data in row: " << line << std::endl;
            }
        }
    }
    file.close();
    return true;
}