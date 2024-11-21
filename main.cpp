#include <galaxy.h>

int main() {
    // Example: Initialize a central node and expand the galaxy
    auto central_node = initNode(0);
    std::cout << "Central node initialized with ID: " << central_node->id << std::endl;

    auto galaxy = expandGalaxySpiral(5);  // Create a galaxy with 5 layers
    std::cout << "Galaxy expanded with " << galaxy.size() << " nodes." << std::endl;

    // Example: Connect some nodes
    if (galaxy.size() > 1) {
        galaxy[0]->connect(galaxy[1], 1.0);
        std::cout << "Connected node " << galaxy[0]->id << " to node " << galaxy[1]->id << std::endl;
    }

    // Example: Propagate data starting from the central node
    propagateData(central_node);

    return 0;
}
