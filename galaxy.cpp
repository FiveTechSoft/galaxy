#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <functional>

// Define PHI (Golden Ratio)
const double PHI = (1.0 + std::sqrt(5.0)) / 2.0;  // Golden Ratio
const size_t MAX_CONNECTIONS = 10;  // Max connections for each node

// GalacticNode Class Definition
class GalacticNode : public std::enable_shared_from_this<GalacticNode> {
public:
    size_t id;
    double activation_value;
    void* data;  // Pointer to custom data
    std::vector<std::shared_ptr<GalacticNode>> links;  // Connections to other nodes
    size_t link_count;
    std::function<void(GalacticNode*)> process;  // Function to define node behavior

    GalacticNode(size_t id, void* data = nullptr, std::function<void(GalacticNode*)> process = nullptr)
        : id(id), activation_value(0), data(data), link_count(0), process(process) {}

    // Function to establish a connection between nodes with a specific weight
    bool connect(std::shared_ptr<GalacticNode> to, double weight) {
        if (link_count >= MAX_CONNECTIONS) {
            std::cerr << "Error: Exceeded maximum number of connections for node " << id << std::endl;
            return false;  // Cannot establish connection due to max connections
        }

        // Create a new connection (can be expanded further if needed)
        links.push_back(to);
        link_count++;

        // Optionally, connect back to the origin node if it's an undirected graph
        to->connect(shared_from_this(), weight);
        return true;
    }

    // Function to process the node (based on its specific logic, e.g., AI or propagation)
    void processNode() {
        if (process) {
            process(this);
        }
    }

    // Adjusts the node's activation value (useful for machine learning algorithms)
    void adjustActivation(double adjustment) {
        activation_value += adjustment;
    }
};

// Connection structure
struct Connection {
    std::shared_ptr<GalacticNode> from;
    std::shared_ptr<GalacticNode> to;
    double weight;  // Strength of the connection

    Connection(std::shared_ptr<GalacticNode> from, std::shared_ptr<GalacticNode> to, double weight)
        : from(from), to(to), weight(weight) {}
};

// Function to expand the galaxy in a spiral pattern
std::vector<std::shared_ptr<GalacticNode>> expandGalaxySpiral(size_t num_layers) {
    std::vector<std::shared_ptr<GalacticNode>> galaxy;
    double angle_step = 360.0 / PHI;  // Define the angle between nodes using PHI
    double radius = 1.0;

    for (size_t i = 0; i < num_layers; ++i) {
        size_t node_id = galaxy.size();  // Unique ID for the node
        std::shared_ptr<GalacticNode> new_node = std::make_shared<GalacticNode>(node_id);

        double angle = angle_step * i;
        double x = radius * cos(angle * M_PI / 180.0);
        double y = radius * sin(angle * M_PI / 180.0);
        new_node->data = new double[2] {x, y};  // Store position data
        
        galaxy.push_back(new_node);
        radius *= PHI;  // Increase radius for the next layer
    }

    return galaxy;
}

// Function to propagate data through the galaxy (similar to neural network processing)
void propagateData(std::shared_ptr<GalacticNode> start_node) {
    std::vector<std::shared_ptr<GalacticNode>> to_process;
    to_process.push_back(start_node);

    while (!to_process.empty()) {
        auto current_node = to_process.back();
        to_process.pop_back();

        current_node->processNode();  // Process the current node

        // Propagate to connected nodes
        for (auto& neighbor : current_node->links) {
            if (neighbor->activation_value == 0.0) {  // Only propagate to unprocessed nodes
                to_process.push_back(neighbor);
            }
        }
    }
}

// Function to adjust weights of the connections between nodes (e.g., for machine learning)
void adjustWeights(std::shared_ptr<GalacticNode> node, double adjustment) {
    for (auto& connection : node->links) {
        // Adjust the weight of each connection
        connection->activation_value += adjustment;
        std::cout << "Adjusted weight of connection from node " << node->id << " to node " << connection->id
                  << " by " << adjustment << ". New weight: " << connection->activation_value << std::endl;
    }
}

// Function to calculate the Euclidean distance between two nodes (for spatial relationships)
double calculateDistance(const GalacticNode& node1, const GalacticNode& node2) {
    double* pos1 = static_cast<double*>(node1.data);
    double* pos2 = static_cast<double*>(node2.data);

    double dx = pos1[0] - pos2[0];
    double dy = pos1[1] - pos2[1];

    return std::sqrt(dx * dx + dy * dy);  // Calculate Euclidean distance
}

// Function to calculate an angle based on the node ID and the Golden Ratio
double calculateAngle(size_t node_id) {
    return node_id * PHI;  // Calculate angle based on the node ID and the Golden Ratio
}

// Function to initialize a new node with optional data and processing function
std::shared_ptr<GalacticNode> initNode(size_t id, void* data = nullptr, std::function<void(GalacticNode*)> process = nullptr) {
    std::shared_ptr<GalacticNode> new_node = std::make_shared<GalacticNode>(id, data, process);
    return new_node;
}
