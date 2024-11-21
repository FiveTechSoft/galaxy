#include "galaxy.h"
#include <stdlib.h>  // Para malloc y free

// Inicializa un nodo galáctico con un identificador único, datos opcionales y una función asociada
GalacticNode *init_node(size_t id, void *data, void (*process)(GalacticNode *self)) {
    // Asignar memoria para el nodo
    GalacticNode *new_node = (GalacticNode *)malloc(sizeof(GalacticNode));
    
    if (new_node == NULL) {
        // En caso de que malloc falle
        return NULL;
    }

    // Inicializar los campos del nodo
    new_node->id = id;
    new_node->activation_value = 0.0; // Valor de activación inicial (puede ajustarse según sea necesario)
    new_node->data = data;            // Asignar datos al nodo
    new_node->links = NULL;           // Inicializar las conexiones como NULL
    new_node->link_count = 0;         // Inicializar el contador de conexiones a 0
    new_node->process = process;      // Asignar la función de procesamiento asociada al nodo
    
    return new_node;
}
