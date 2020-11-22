#include <string.h>
#include <time.h>

#include "list/array_list.h"

int main() {

    if(PROG < PROG_NO_ERROR_NO_LEAK || PROG > PROG_ERROR_LEAK) {
        fprintf(stderr, "Error: PROG should be between %i and %i.\nRun: make clean && make PROG=...\n", PROG_NO_ERROR_NO_LEAK, PROG_ERROR_LEAK);
        return -1;
    }

    const int size       = 8;
    array_list_t *lists = malloc(sizeof(array_list_t) * size);

    srand(time(NULL));

    // Init lists
    for(register int i = 0; i <  size; i++){
        lists[i] = new_array_list();
       
        assert(lists[i] != NULL && is_empty(lists[i]));

        int nb_elem = rand() % 16;
        for(int j = 0; j < nb_elem; j++) {
            add(lists[i], (element_t *) &j);
        }
    }

    // Display information on each list
    for(register int i = 0; i <  size; i++){
        print_list(lists[i]);
        printf("\n");
    }

    // Destruct each list
    for(register int i = 0; i < size; i++){
        #if PROG == PROG_NO_ERROR_LEAK
            if(i % 2 == 0) {
                destruct(lists[i]);
            }
        #else
            destruct(lists[i]);
        #endif
    }
    free(lists);

    return 0;
}
