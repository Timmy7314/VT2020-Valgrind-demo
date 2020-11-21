#include <list/array_list.h>

array_list_t new_array_list(){
    array_list_t list = malloc(sizeof(struct array_list));

    list->size      = 1;
    list->cur_index = 0;
    list->array     = malloc(sizeof(element_t *) * list->size);

    return list;
}

int add(array_list_t list, element_t *obj){
    if(list == NULL)
        return -1;

    if(list->cur_index >= list->size){
        list->size  = list->size << 1;
        list->array = realloc(list->array, sizeof(element_t *) * list->size);

        if(list->array == NULL)
            return -1;
    }

    list->array[list->cur_index++] = obj;

    return 0;
}

int add_at(array_list_t list, unsigned int i, element_t *obj){
    if(list == NULL)
        return -1;

    while(i >= list->size && list->array != NULL){
        list->size  = list->size << 1;
        list->array = realloc(list->array, sizeof(element_t *) * list->size);
    }

    if(list->array == NULL)
        return -1;

    list->array[i]  = obj;
    list->cur_index = i;

    return 0;
}

int add_all(array_list_t list, array_list_t elems){
    if(list == NULL || elems == NULL)
        return -1;

    while(list->cur_index + elems->cur_index >= list->size && list->array != NULL){
        list->size  = list->size << 1;
        list->array = realloc(list->array, sizeof(element_t *) * list->size);
    }

    if(list->array == NULL)
        return -1;

    register unsigned int i = 0;
    while(i < elems->cur_index){
        list->array[list->cur_index + i] = elems->array[i];
        i++;
    }

    list->cur_index = i;

    return 0;
}

int contains(array_list_t list,element_t *obj){
    if(list == NULL || obj == NULL)
        return 0;

    register          int res = 0;
    register unsigned int i   = 0;

    for(; i < list->size && res == 0; i++){
        if(list->array[i] == obj)
            res = 1;
    }

    return res;
}

int index_of(array_list_t list,element_t *obj){
    if(list == NULL || obj == NULL)
        return 0;

    int res = -1;

    register unsigned int i = 0;
    for(; i < list->size && res < 0; i++){
        if(list->array[i] == obj)
            res = i;
    }

    return res;
}

int is_empty(array_list_t list){
    if(list == NULL)
        return 0;
    return list->cur_index == 0;
}

int size(array_list_t list){
    if(list == NULL)
        return -1;

    return list->cur_index;
}

element_t *remove_at(array_list_t list, unsigned int i){
    assert(list != NULL);
    assert(i < list->size);

    element_t *res = NULL;

    res = list->array[i];
    list->array[i] = NULL;

    return res;
}

element_t *get(array_list_t list, unsigned int i){
    assert(list != NULL);
    assert(i < list->size);

    return list->array[i];
}

element_t remove_obj(array_list_t list,element_t *obj){
    assert(list != NULL);
    assert(obj != NULL);

    remove_at(list, index_of(list, obj));
}

element_t clear(array_list_t list){
    assert(list != NULL);

    list->cur_index = 0;
    list->size      = 1;
    list->array     = realloc(list->array, sizeof(element_t *) * list->size);
}

element_t update(array_list_t list, unsigned int i, element_t *obj){
    assert(list != NULL);
    assert(i < list->size);
    assert(obj != NULL);

    list->array[i] = obj;
}

element_t print_list(array_list_t list){
    assert(list != NULL);

    printf("Size: %i\n", list->size);
    printf("Elements inside: %i\n", list->cur_index);
    printf("Elements: \n");

    register unsigned int i = 0;
    for(; i < list->cur_index; i++){
        printf("\t- [%i] %p\n", i, list->array[i]);
    }
}

element_t destruct(array_list_t list){
    assert(list != NULL);

    free(list->array);
    free(list);
}
