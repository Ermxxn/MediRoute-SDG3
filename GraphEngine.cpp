#include "../include/GraphEngine.hpp"
#include <queue>
#include <limits>
#include <algorithm>

void GraphEngine::addEdge(const std::string& source, const std::string& destination, int weight) {
    adjacencyList[source].push_back({destination, weight});
    adjacencyList[destination].push_back({source, weight}); 
}

std::vector<std::string> GraphEngine::calculateFastestPath(const std::string& startNode, const std::string& endNode) {
    std::unordered_map<std::string, int> travelTimes;
    std::unordered_map<std::string, std::string> previousNode;
    
    auto compare = [&travelTimes](const std::string& a, const std::string& b) {
        return travelTimes[a] > travelTimes[b];
    };
    std::priority_queue<std::string, std::vector<std::string>, decltype(compare)> emergencyQueue(compare);

    for (const auto& pair : adjacencyList) {
        travelTimes[pair.first] = std::numeric_limits<int>::max();
    }
    travelTimes[startNode] = 0;
    emergencyQueue.push(startNode);

    while (!emergencyQueue.empty()) {
        std::string current = emergencyQueue.top();
        emergencyQueue.pop();

        if (current == endNode) break;

        for (const auto& neighbor : adjacencyList[current]) {
            int newTime = travelTimes[current] + neighbor.travel_time_minutes;
            if (newTime < travelTimes[neighbor.destination]) {
                travelTimes[neighbor.destination] = newTime;
                previousNode[neighbor.destination] = current;
                emergencyQueue.push(neighbor.destination);
            }
        }
    }

    std::vector<std::string> optimalPath;
    for (std::string at = endNode; at != ""; at = previousNode[at]) {
        optimalPath.push_back(at);
        if (at == startNode) break;
    }
    std::reverse(optimalPath.begin(), optimalPath.end());
    return optimalPath;
}