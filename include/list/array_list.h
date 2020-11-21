#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "constants.h"

typedef void element_t;

typedef struct array_list{

    element_t **array;
    unsigned int size;
    unsigned int cur_index;

} *array_list_t;


array_list_t new_array_list();

int add(array_list_t list, element_t *obj);
int add_at(array_list_t list, unsigned int i, element_t *obj);
int add_all(array_list_t list, array_list_t elems);
int contains(array_list_t list,element_t *obj);
int index_of(array_list_t list,element_t *obj);
int is_empty(array_list_t list);
int size(array_list_t list);

void *remove_at(array_list_t list, unsigned int i);
void *get(array_list_t list, unsigned int i);

void remove_obj(array_list_t list,element_t *obj);
void clear(array_list_t list);
void update(array_list_t list, unsigned int i, element_t *obj);
void print_list(array_list_t list);
void destruct(array_list_t list);

#endif //__ARRAY_LIST_H__
