#include "../include/GraphEngine.hpp"
#include <iostream>
#include <cassert>

void runTests() {
    GraphEngine testRouter;

    testRouter.addEdge("H", "D", 3);
    testRouter.addEdge("A", "H", 5);
    testRouter.addEdge("A", "B", 2);
    testRouter.addEdge("B", "H", 2);

    std::vector<std::string> expectedPath1 = {"A", "B", "H", "D"};
    std::vector<std::string> calculatedPath1 = testRouter.calculateFastestPath("A", "D");
    assert(calculatedPath1 == expectedPath1);
    std::cout << "[Pass] Test 1: A -> D correctly routed via B." << std::endl;

    std::vector<std::string> expectedPath2 = {"H", "D"};
    std::vector<std::string> calculatedPath2 = testRouter.calculateFastestPath("H", "D");
    assert(calculatedPath2 == expectedPath2);
    std::cout << "[Pass] Test 2: H -> D correctly routed directly." << std::endl;
}

int main() {
    std::cout << "=== Running MediRoute Route Tests ===" << std::endl;
    runTests();
    return 0;
}