#include <list/array_list.h>
#include <string.h>
#include <assert.h>

static void help(void){
    printf("Program: listlib_tes\n");
    printf("Usage:   listlib_tes <arg0>\n");
    printf("Args:\n");
    printf("\t- array_list  \tTo test array_list\n");
    printf("\t- linked_list \tTo test linked_list\n");
    printf("\t- hash_map    \tTo test hash_map\n");
}

int test_array_list(){
    const int NB_ELEMENT = 10;
    const int VALUES[]   = {0,1,2,3,4,5,6,7,8,9};

    array_list_t list = new_array_list();
    assert(list != NULL && is_empty(list));

    for(int i = 0; i < NB_ELEMENT; i++){
        assert(add(list, (void *) &VALUES[i]) == 0);
    }
    assert(size(list) == NB_ELEMENT);

    for (int i = 0; i < NB_ELEMENT; i++) {
        int *elem = (int *) get(list, i);
        assert(*elem == i);
        assert(index_of(list, (void *) elem) == i);
    }

    int elem = 14;
    update(list, 0, (void *) &elem);
    assert(*((int *) get(list,0)) == elem);
    assert(contains(list, (void *) &elem));

    clear(list);
    assert(size(list) == 0);
    destruct(list);

    return 0;
}

void test_linked_list(){
    printf("Not implement yet");
}

void test_hash_map(){
    printf("Not implement yet");
}

int main(int argc, char **argv){

    if(argc < 2){
        help();
        return -1;
    }

    if(!strcmp("array_list",argv[1])){
        printf("Test 1: %s\n", !test_array_list() ? "OK" : "KO");
    }else if(!strcmp("linked_list",argv[1])){
        test_linked_list();
    }else if(!strcmp("hash_map",argv[1])){
        test_hash_map();
    }else{
        help();
        return -1;
    }

    return 0;
}
