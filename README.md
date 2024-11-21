# galaxy
A modular and dynamic programming language inspired by the galactic structure, designed to model complex, adaptive, and hierarchical systems through interconnected nodes and natural mathematical patterns like Fibonacci and the golden ratio.

Explanation of the Components

Constants

PHI: The golden ratio, used to generate spiral patterns.
MAX_CONNECTIONS: An optional limit to avoid infinite cycles or uncontrolled networks.
Data Structures

GalacticNode: Represents a node in the galaxy. It includes:
id: A unique identifier for the node.
activation_value: For systems using AI.
data: A generic pointer to store custom information.
links and link_count: Connections to other nodes and their count.
process: A pointer to a function that defines the node's behavior.
Connection: Defines the connections between nodes, with a weight to model relationships.
Main Functions These functions are the core of the language:

init_node: Initializes a node with optional data and an associated function.
connect_nodes: Establishes connections between nodes and defines their weight.
expand_galaxy_spiral: Creates new nodes in a spiral arrangement, based on Fibonacci patterns or golden angles.
propagate_data: Simulates the propagation of data through the galaxy, useful for implementing neural networks or processing systems.
adjust_weights: Adjusts the weights of the connections, useful for machine learning.
free_node: Frees the resources associated with a node.
Auxiliary Functions

calculate_distance: Determines the distance between nodes in different layers.
calculate_angle: Calculates the positioning angle using the golden ratio.
main.c This example initializes a central node, expands the galaxy in three layers, propagates data from the central node, and finally frees the memory.

Future Extensions

Learning Algorithms: Implement specific functions for supervised or reinforcement learning.
Visualization: Add support for exporting the structure in a visual format like JSON or Graphviz.
Asynchronous Connections: Support for parallel or real-time processing.
