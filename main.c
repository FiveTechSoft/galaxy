#include "galaxy.h"
#include <stdio.h>

void example_process(GalacticNode *self) {
    printf("Procesando nodo %zu con valor de activación %.2f\n", self->id, self->activation_value);
}

int main() {
    // Crear nodo central.
    GalacticNode *center = init_node(0, NULL, example_process);

    // Expander la galaxia.
    expand_galaxy_spiral(center, 3, 1.0);

    // Propagar datos desde el nodo central.
    propagate_data(center, 1.0);

    // Liberar recursos.
    free_node(center);

    return 0;
}
