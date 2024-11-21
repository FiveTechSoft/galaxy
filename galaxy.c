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

// Establece una conexión entre dos nodos y define su peso
bool connect_nodes(GalacticNode *from, GalacticNode *to, double weight) {
    if (from == NULL || to == NULL) {
        // Si alguno de los nodos es NULL, no se puede establecer la conexión
        return false;
    }

    // Verificar si el número de conexiones del nodo 'from' no supera el límite máximo
    if (from->link_count >= MAX_CONNECTIONS) {
        return false;  // No se puede agregar más conexiones
    }

    // Crear un nuevo arreglo de conexiones (más grande que el anterior)
    GalacticNode **new_links = (GalacticNode **)realloc(from->links, (from->link_count + 1) * sizeof(GalacticNode *));
    if (new_links == NULL) {
        return false;  // Falló la reasignación de memoria
    }

    // Actualizar la lista de conexiones del nodo 'from'
    from->links = new_links;
    from->links[from->link_count] = to;  // Agregar el nuevo nodo de destino a las conexiones
    from->link_count++;  // Incrementar el contador de conexiones

    // Crear una nueva conexión (opcional: para manejar el peso de la conexión, se podría usar un array o estructura separada)
    Connection *new_connection = (Connection *)malloc(sizeof(Connection));
    if (new_connection == NULL) {
        return false;  // Falló la asignación de memoria para la nueva conexión
    }
    
    // Inicializar la nueva conexión
    new_connection->from = from;
    new_connection->to = to;
    new_connection->weight = weight;

    // Opcionalmente, almacenar la conexión en una lista global o dentro de cada nodo
    // Para ahora, esta parte está implícita, ya que se podría gestionar de diversas formas.

    return true;
}

