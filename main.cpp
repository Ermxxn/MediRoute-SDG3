#include <iostream>
#include "../include/GraphEngine.hpp"
#include "../include/MapLoader.hpp"

/**
 * @brief Entry point for the MediRoute SDG 3 Application.
 * Initializes the city grid from a CSV and simulates an emergency routing request.
 */
int main() {
    GraphEngine router;

    std::cout << "=== MediRoute: SDG 3 Emergency Dispatch Engine ===" << std::endl;
    std::cout << "[System] Loading city infrastructure from data/city_map.csv...\n";
    
    // Dynamically load the graph weights from the CSV file
    if (!MapLoader::loadCityMap("data/city_map.csv", router)) {
        std::cerr << "[Error] Failed to initialize graph engine." << std::endl;
        return 1;
    }

    std::cout << "[System] Calculating fastest drone supply route...\n" << std::endl;
    
    // Calculate route from Accident Site (A) to Distribution Center (D)
    std::vector<std::string> path = router.calculateFastestPath("A", "D");

    std::cout << "Optimal Emergency Route Executed: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << (i < path.size() - 1 ? " -> " : "");
    }
    std::cout << "\n\n[Status] Patient transit time mathematically minimized." << std::endl;

    return 0;
}