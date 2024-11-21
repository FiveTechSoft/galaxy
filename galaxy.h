#ifndef GALAXY_H
#define GALAXY_H

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <functional>

const double PHI = 1.61803398875;  // Número áureo
const size_t MAX_CONNECTIONS = 100; // Límite de conexiones por nodo

// Declaración de la clase GalacticNode
class GalacticNode;

// Estructura que define una conexión entre nodos
struct Connection {
    std::shared_ptr<GalacticNode> from;
    std::shared_ptr<GalacticNode> to;
    double weight;  // Peso de la conexión

    Connection(std::shared_ptr<GalacticNode> f, std::shared_ptr<GalacticNode> t, double w)
        : from(f), to(t), weight(w) {}
};

// Clase que representa un nodo galáctico
class GalacticNode {
public:
    size_t id;                  // Identificador único para el nodo
    double activation_value;    // Valor de activación (para IA)
    void* data;                 // Datos personalizados del nodo
    std::vector<std::shared_ptr<GalacticNode>> links;  // Conexiones a otros nodos
    size_t link_count;          // Contador de conexiones
    std::function<void(GalacticNode*)> process; // Función de procesamiento del nodo

    // Constructor
    GalacticNode(size_t id, void* data = nullptr, std::function<void(GalacticNode*)> process = nullptr)
        : id(id), activation_value(0.0), data(data), link_count(0), process(process) {}

    // Método para conectar nodos
    bool connect(std::shared_ptr<GalacticNode> to, double weight);

    // Método para procesar el nodo
    void processNode() {
        if (process) {
            process(this);
        }
    }

    // Método para ajustar el valor de activación
    void adjustActivation(double value) {
        activation_value += value;
    }

    // Destructor
    ~GalacticNode() {
        // No es necesario liberar memoria manualmente debido a shared_ptr
    }
};

// Función para expandir la galaxia en una espiral basada en Fibonacci o el número áureo
std::vector<std::shared_ptr<GalacticNode>> expandGalaxySpiral(size_t num_layers);

// Función para propagar datos a través de la galaxia (útil para redes neuronales o propagación de información)
void propagateData(std::shared_ptr<GalacticNode> start_node);

// Función para ajustar los pesos de las conexiones
void adjustWeights(std::shared_ptr<GalacticNode> node, double adjustment);

// Función para calcular la distancia entre dos nodos (basada en sus posiciones en capas)
double calculateDistance(const GalacticNode& node1, const GalacticNode& node2);

// Función para calcular el ángulo de un nodo basado en el número áureo
double calculateAngle(size_t node_id);

// Función para crear un nodo y asociar su función de procesamiento
std::shared_ptr<GalacticNode> initNode(size_t id, void* data = nullptr, std::function<void(GalacticNode*)> process = nullptr);

#endif // GALAXY_H
