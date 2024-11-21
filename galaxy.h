#ifndef GALAXY_H
#define GALAXY_H

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <functional>

const double PHI = 1.61803398875;  // The Golden Ratio
const size_t MAX_CONNECTIONS = 100; // Maximum connections per node

// Forward declaration of the GalacticNode class
class GalacticNode;

// Structure defining a connection between nodes
struct Connection {
    std::shared_ptr<GalacticNode> from;  // The originating node
    std::shared_ptr<GalacticNode> to;    // The destination node
    double weight;  // The weight of the connection

    Connection(std::shared_ptr<GalacticNode> f, std::shared_ptr<GalacticNode> t, double w)
        : from(f), to(t), weight(w) {}
};

// GalacticNode class representing a node in the galaxy
class GalacticNode {
public:
    size_t id;                  // Unique identifier for the node
    double activation_value;    // Activation value (for AI systems)
    void* data;                 // Pointer to store custom data
    std::vector<std::shared_ptr<GalacticNode>> links;  // Connections to other nodes
    size_t link_count;          // Number of active connections
    std::function<void(GalacticNode*)> process; // Function to define node behavior

    // Constructor for GalacticNode
    GalacticNode(size_t id, void* data = nullptr, std::function<void(GalacticNode*)> process = nullptr)
        : id(id), activation_value(0.0), data(data), link_count(0), process(process) {}

    // Connects this node to another node with a specific weight
    bool connect(std::shared_ptr<GalacticNode> to, double weight);

    // Processes the node (executes its associated process function)
    void processNode() {
        if (process) {
            process(this);
        }
    }

    // Adjusts the activation value of the node
    void adjustActivation(double value) {
        activation_value += value;
    }

    // Destructor - No need to manually manage memory due to shared_ptr
    ~GalacticNode() {}
};

// Function to expand the galaxy in a spiral pattern based on Fibonacci or the Golden Ratio
std::vector<std::shared_ptr<GalacticNode>> expandGalaxySpiral(size_t num_layers);

// Function to propagate data through the galaxy (useful for neural networks or information propagation)
void propagateData(std::shared_ptr<GalacticNode> start_node);

// Function to adjust the weights of connections
void adjustWeights(std::shared_ptr<GalacticNode> node, double adjustment);

// Function to calculate the distance between two nodes (based on their positions in layers)
double calculateDistance(const GalacticNode& node1, const GalacticNode& node2);

// Function to calculate the angle of a node based on the Golden Ratio
double calculateAngle(size_t node_id);

// Function to initialize a node with an ID, optional data, and an optional processing function
std::shared_ptr<GalacticNode> initNode(size_t id, void* data = nullptr, std::function<void(GalacticNode*)> process = nullptr);

#endif // GALAXY_H
