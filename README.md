# galaxy
# A modular and dynamic programming language inspired by the galactic structure, designed to model complex, adaptive, and hierarchical systems through interconnected nodes and natural mathematical patterns like Fibonacci and the golden ratio.

# Galaxy Programming Language

**Galaxy** is a modular and dynamic programming language inspired by the structure of galaxies, designed to model complex, adaptive, and hierarchical systems through interconnected nodes and natural mathematical patterns like the **Golden Ratio** (PHI) and **Fibonacci sequences**. The language provides an intuitive framework for creating interconnected networks that evolve over time, making it an ideal tool for applications in **artificial intelligence**, **machine learning**, **neural networks**, **complex systems simulation**, and more.

## Key Features

- **Natural Growth Structure**: Nodes are connected in a galaxy-like network that evolves dynamically, inspired by the growth patterns of galaxies and the Golden Ratio.
- **Node-based System**: The core building block of Galaxy is the **GalacticNode**, each representing an entity with data, behaviors, and connections to other nodes.
- **Adaptive Connections**: Connections between nodes can be weighted and dynamically adjusted, enabling the modeling of systems that learn or adapt over time.
- **Mathematical Foundations**: The use of the **Golden Ratio** and **Fibonacci sequences** to define node placement, connection weights, and growth patterns ensures the system evolves naturally and efficiently.
- **Data Propagation and AI Integration**: Supports the propagation of data across nodes, making it suitable for building **neural networks**, **AI models**, and **machine learning algorithms**.

## Language Structure

The **Galaxy language** is organized around the concept of nodes connected by links, forming a galaxy-like structure. Nodes can represent entities in a system, such as objects, components, or processes, and can evolve dynamically through interactions with other nodes.

### Core Components

- **PHI (Golden Ratio)**: A constant used to define proportions, distances, and angles for spiraling node layouts and connection adjustments.
- **MAX_CONNECTIONS**: A limit to prevent excessive complexity and infinite loops by restricting the number of connections each node can have.
- **GalacticNode**: The primary data structure representing nodes. Each node has attributes like `id`, `activation_value`, `data`, and a list of connections (`links`).
- **Connections**: Nodes are connected to each other through links, which have weights to define the strength or influence of the relationship between them.

### Functions

- `initNode()`: Initializes a new node with custom data and optional behaviors.
- `connectNodes()`: Establishes connections between nodes, setting their weight.
- `expandGalaxySpiral()`: Expands the galaxy in a spiral pattern, using the Golden Ratio for node placement.
- `propagateData()`: Propagates data across the network of nodes, useful for tasks like signal transmission and AI training.
- `adjustWeights()`: Modifies connection weights, enabling the adaptation of the network for learning and optimization.

## Use Cases

### Machine Learning and AI

- **Neural Networks**: Easily implement neural networks with dynamic weights and adaptive learning algorithms.
- **Supervised & Reinforcement Learning**: Implement AI models that evolve and adapt based on input data and feedback from the environment.
  
### Complex Systems and Simulation

- **Dynamic Systems**: Model and simulate complex, evolving systems like social networks, biological systems, and economic models.
- **Optimization**: Use Galaxy's adaptive network for optimization tasks, such as resource allocation, pathfinding, and decision-making.

### Spatial and Geometric Modeling

- **Geospatial Applications**: Use the geometric properties of the Golden Ratio to model spatial systems and distributions efficiently.
- **Simulations**: Simulate growth patterns, resource distribution, or the spread of information in systems that require spatial awareness.

## Getting Started

### Prerequisites

- **C++ Compiler**: Galaxy is implemented in C++ and requires a C++11 or later compiler.
- **Development Environment**: Any IDE or text editor that supports C++ development (e.g., Visual Studio, Xcode, or VSCode).
