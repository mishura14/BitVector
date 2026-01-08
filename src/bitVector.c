#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>



typedef struct{
    uint8_t *data;
    size_t length;
    size_t capacity;
}bitVector;
//создание битового вектора
bitVector *create_bitVector(size_t capacity)
{
    bitVector * bv = malloc(sizeof *bv);
    if(!bv){
        return NULL;
    }
    bv->data = malloc((capacity + 7) / 8);
    if(!bv->data){
        free(bv);
        return NULL;
    }
    bv->capacity = capacity;
    bv->length = 0;
    return bv;
}

//удаление битового вектора
void free_bitVector(bitVector *bv)
{
    free(bv->data);
    free(bv);
}
//увеличение битового вектора
void reserve_bitVector(bitVector *bv, size_t new_capacity)
{
    if(new_capacity <= bv->capacity){
        return;
    }
    size_t old_bytes = (bv->capacity + 7) / 8;
    size_t new_bytes = (new_capacity + 7) / 8;

    uint8_t *new_data = realloc(bv->data, new_bytes);
    if (!new_data){
        perror("realloc");
        exit(1);
    }
    memset(new_data + old_bytes,0,new_bytes - old_bytes);
    bv->data = new_data;
    bv->capacity = new_capacity;
}
