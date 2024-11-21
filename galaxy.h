#ifndef GALAXY_H
#define GALAXY_H

#include <stddef.h>  // Para tipos de tamaño estándar (size_t).
#include <stdbool.h> // Para tipos booleanos.

// --------------------------------------------------------------------
// Definiciones de constantes
// --------------------------------------------------------------------
#define PHI 1.61803398875 // Número áureo
#define MAX_CONNECTIONS 100 // Máximo número de conexiones por nodo

// --------------------------------------------------------------------
// Estructuras de Datos
// --------------------------------------------------------------------

// Estructura básica para un nodo en la galaxia.
typedef struct GalacticNode {
    size_t id;                     // Identificador único del nodo.
    double activation_value;       // Valor de activación (para IA).
    void *data;                    // Puntero genérico a datos.
    struct GalacticNode **links;   // Lista de nodos conectados.
    size_t link_count;             // Número de conexiones actuales.
    void (*process)(struct GalacticNode *self); // Función asociada al nodo.
} GalacticNode;

// Estructura para conexiones entre nodos.
typedef struct Connection {
    GalacticNode *from; // Nodo de origen.
    GalacticNode *to;   // Nodo de destino.
    double weight;      // Peso de la conexión (importancia).
} Connection;

// --------------------------------------------------------------------
// Funciones Principales
// --------------------------------------------------------------------

// Inicializa un nodo galáctico.
GalacticNode *init_node(size_t id, void *data, void (*process)(GalacticNode *self));

// Conecta dos nodos con un peso opcional.
bool connect_nodes(GalacticNode *from, GalacticNode *to, double weight);

// Expande la galaxia añadiendo nodos en una disposición espiral.
void expand_galaxy_spiral(GalacticNode *center, size_t layers, double base_distance);

// Propaga información desde un nodo a sus conexiones.
void propagate_data(GalacticNode *node, double input_value);

// Ajusta los pesos de las conexiones de un nodo.
void adjust_weights(GalacticNode *node, double error, double learning_rate);

// Libera la memoria asociada a un nodo.
void free_node(GalacticNode *node);

// --------------------------------------------------------------------
// Funciones Auxiliares
// --------------------------------------------------------------------

// Calcula la distancia entre nodos según la capa.
double calculate_distance(size_t layer);

// Calcula el ángulo áureo para la expansión espiral.
double calculate_angle(size_t layer);

#endif // GALAXY_H
