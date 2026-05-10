#pragma once
#include "NodeDefinitions.hpp"
#include <unordered_map>
#include <vector>
#include <string>

/**
 * @brief Core routing engine using Dijkstra's algorithm for emergency response.
 * Aligns with SDG 3 by minimizing transit time for critical medical supplies.
 */
class GraphEngine {
private:
    std::unordered_map<std::string, std::vector<Edge>> adjacencyList;

public:
    /**
     * @brief Adds a bi-directional route to the city map.
     */
    void addEdge(const std::string& source, const std::string& destination, int weight);

    /**
     * @brief Calculates the absolute fastest route.
     */
    std::vector<std::string> calculateFastestPath(const std::string& startNode, const std::string& endNode);
};