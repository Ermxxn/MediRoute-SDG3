#pragma once
#include "GraphEngine.hpp"
#include <string>

/**
 * @brief Utility class to load city infrastructure data from external files.
 */
class MapLoader {
public:
    /**
     * @brief Parses a CSV file and populates the GraphEngine.
     */
    static bool loadCityMap(const std::string& filepath, GraphEngine& engine);
};