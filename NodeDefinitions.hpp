#pragma once
#include <string>
#include <vector>

/**
 * @brief Represents a traffic route between two city nodes.
 */
struct Edge {
    std::string destination;
    int travel_time_minutes; ///< The "weight" representing traffic/distance
};

/**
 * @brief Represents a medical facility, accident site, or intersection.
 */
struct CityNode {
    std::string id;
    std::string type; ///< e.g., "Hospital", "Clinic", "Intersection"
    std::vector<Edge> connections;
};