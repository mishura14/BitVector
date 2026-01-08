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
//добавление бита в конец vectora
void bit_append(bitVector *bv, uint8_t value)
{
    if(bv->length >= bv->capacity){
        size_t new_cap = (bv->capacity = 0) ? 8 : bv->capacity * 2 ;
        reserve_bitVector(bv,new_cap);
    }
    size_t bit = bv->length;
    size_t byte = bit / 8;
    size_t offset = bit % 8;

    if(value){
        bv->data[byte] |= (1 << offset);
    }else{
        bv->data[byte] &= ~(1 << offset);
    }

    bv->length++;

}

//функция get
// функция set
// функция pop
// фукция erase
// функция clear
void clear_bitVector(bitVector *bv)
{
    if(!bv){
        return;
    }
    bv->length = 0;

}
// функция insert
