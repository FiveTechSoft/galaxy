#include "galaxy.h"

// Function to connect two nodes
bool GalacticNode::connect(std::shared_ptr<GalacticNode> to, double weight) {
    if (link_count >= MAX_CONNECTIONS) {
        std::cerr << "Error: Exceeded maximum number of connections for node " << id << std::endl;
        return false;  // Exceeds maximum connections, cannot connect
    }

    // Create a new connection and add it to the node's link list
    std::shared_ptr<Connection> new_connection = std::make_shared<Connection>(shared_from_this(), to, weight);
    links.push_back(to);
    link_count++;

    // Optionally, also add a reciprocal connection (if undirected graph is assumed)
    to->connect(shared_from_this(), weight);

    return true;
}

// Function to expand the galaxy in a spiral pattern
std::vector<std::shared_ptr<GalacticNode>> expandGalaxySpiral(size_t num_layers) {
    std::vector<std::shared_ptr<GalacticNode>> galaxy;
    double angle_step = 360.0 / PHI; // Use the Golden Ratio to create angles
    double radius = 1.0;

    for (size_t i = 0; i < num_layers; ++i) {
        // Create a new node for each layer
        size_t node_id = galaxy.size();  // Unique ID for the node
        std::shared_ptr<GalacticNode> new_node = std::make_shared<GalacticNode>(node_id);

        // Position the node in a spiral using radius and angle
        double angle = angle_step * i;
        double x = radius * cos(angle * M_PI / 180.0);
        double y = radius * sin(angle * M_PI / 180.0);
        new_node->data = new double[2] {x, y};  // Store position as custom data

        galaxy.push_back(new_node);

        // Increase radius for the next layer
        radius *= PHI;
    }

    return galaxy;
}

// Function to propagate data through the galaxy starting from a given node
void propagateData(std::shared_ptr<GalacticNode> start_node) {
    std::vector<std::shared_ptr<GalacticNode>> to_process;
    to_process.push_back(start_node);

    while (!to_process.empty()) {
        auto current_node = to_process.back();
        to_process.pop_back();

        // Process the current node
        current_node->processNode();

        // Propagate to connected nodes
        for (auto& neighbor : current_node->links) {
            if (neighbor->activation_value == 0.0) {  // Check if node is unprocessed
                to_process.push_back(neighbor);
            }
        }
    }
}

// Function to adjust weights of connections (can be used in learning algorithms)
void adjustWeights(std::shared_ptr<GalacticNode> node, double adjustment) {
    for (auto& connection : node->links) {
        // Adjust the weight of each connection by the specified amount
        connection->weight += adjustment;
        std::cout << "Adjusted weight of connection from node " << node->id << " to node " << connection->id
                  << " by " << adjustment << ". New weight: " << connection->weight << std::endl;
    }
}

// Function to calculate the distance between two nodes
double calculateDistance(const GalacticNode& node1, const GalacticNode& node2) {
    double* pos1 = static_cast<double*>(node1.data);
    double* pos2 = static_cast<double*>(node2.data);

    double dx = pos1[0] - pos2[0];
    double dy = pos1[1] - pos2[1];

    return std::sqrt(dx * dx + dy * dy);
}

// Function to calculate the angle of a node based on its ID and the Golden Ratio
double calculateAngle(size_t node_id) {
    return node_id * PHI;  // The node ID scaled by the Golden Ratio gives a natural angle
}

// Function to initialize a new GalacticNode
std::shared_ptr<GalacticNode> initNode(size_t id, void* data, std::function<void(GalacticNode*)> process) {
    std::shared_ptr<GalacticNode> new_node = std::make_shared<GalacticNode>(id, data, process);
    return new_node;
}
