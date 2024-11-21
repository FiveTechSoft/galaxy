# galaxy
A modular and dynamic programming language inspired by the galactic structure, designed to model complex, adaptive, and hierarchical systems through interconnected nodes and natural mathematical patterns like Fibonacci and the golden ratio

Explicación de los Componentes
1. Constantes
PHI: El número áureo, usado para generar patrones espirales.
MAX_CONNECTIONS: Un límite opcional para evitar ciclos infinitos o redes descontroladas.

2. Estructuras de Datos
GalacticNode: Representa un nodo en la galaxia. Incluye:
id: Identificador único para el nodo.
activation_value: Para sistemas que usen IA.
data: Puntero genérico para almacenar información personalizada.
links y link_count: Conexiones a otros nodos y su cantidad.
process: Puntero a una función que define el comportamiento del nodo.
Connection: Define las conexiones entre nodos, con un peso para modelar relaciones.

3. Funciones Principales
Estas funciones son la base del lenguaje:

init_node: Inicializa un nodo con datos opcionales y una función asociada.
connect_nodes: Establece conexiones entre nodos y define su peso.
expand_galaxy_spiral: Crea nuevos nodos en una disposición espiral, según patrones de Fibonacci o ángulos áureos.
propagate_data: Simula la propagación de datos a través de la galaxia, útil para implementar redes neuronales o sistemas de procesamiento.
adjust_weights: Ajusta los pesos de las conexiones, útil para aprendizaje automático.
free_node: Libera los recursos asociados a un nodo.

4. Funciones Auxiliares
calculate_distance: Determina la distancia entre nodos en diferentes capas.
calculate_angle: Calcula el ángulo de posicionamiento usando el número áureo.

main.c
Este ejemplo inicializa un nodo central, expande la galaxia en tres capas, propaga datos desde el nodo central y finalmente libera la memoria.

Futuras Extensiones
Algoritmos de aprendizaje: Implementar funciones específicas para aprendizaje supervisado o por refuerzo.
Visualización: Añadir soporte para exportar la estructura en un formato visual como JSON o Graphviz.
Conexiones asíncronas: Soporte para procesamiento paralelo o en tiempo real.
