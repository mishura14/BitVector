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

//функция set
void bit_set(bitVector *bv, size_t index, uint8_t value)
{
    if (!bv || !bv->data) return;
    if (index >= bv->length) return;

    size_t byte_index = index / 8;
    size_t bit_index  = index % 8;

    if (value)
        bv->data[byte_index] |= (1 << bit_index);
    else
        bv->data[byte_index] &= ~(1 << bit_index);
}

// функция get
uint8_t bit_get(const bitVector *bv, size_t index)
{
    if (!bv || !bv->data) return 0;
    if (index >= bv->length) return 0;

    size_t byte_index = index / 8;
    size_t bit_index  = index % 8;
    return (bv->data[byte_index] >> bit_index) & 1;
}

// функция pop
uint8_t bit_pop(bitVector *bv)
{
    if (!bv || !bv->data) return 0;
    if (bv->length == 0) return 0;

    size_t last_index = bv->length - 1;
    size_t byte_index = last_index / 8;
    size_t bit_index  = last_index % 8;

    uint8_t bit_val = (bv->data[byte_index] >> bit_index) & 1;


    bv->length--;

    return bit_val;
}

// фукция erase
void bit_erase(bitVector *bv, size_t index)
{
    if (!bv || !bv->data) return;
    if (index >= bv->length) return;

    for (size_t i = index; i < bv->length - 1; i++) {
        size_t src_byte = (i + 1) / 8;
        size_t src_bit  = (i + 1) % 8;

        size_t dst_byte = i / 8;
        size_t dst_bit  = i % 8;

        uint8_t bit_val = (bv->data[src_byte] >> src_bit) & 1;

        if (bit_val)
            bv->data[dst_byte] |= (1 << dst_bit);
        else
            bv->data[dst_byte] &= ~(1 << dst_bit);
    }

    bv->length--;
}

// функция clear
void clear_bitVector(bitVector *bv)
{
    if(!bv){
        return;
    }
    bv->length = 0;

}
// функция insert
void bit_insert(bitVector *bv, size_t index, uint8_t value)
{
    if (!bv || !bv->data) return;
    if (index > bv->length) return;

    if (bv->length >= bv->capacity) {
        size_t new_cap = (bv->capacity == 0) ? 8 : bv->capacity * 2;
        reserve_bitVector(bv, new_cap);
    }

    for (size_t i = bv->length; i > index; i--) {
        size_t src_byte = (i - 1) / 8;
        size_t src_bit  = (i - 1) % 8;

        size_t dst_byte = i / 8;
        size_t dst_bit  = i % 8;

        uint8_t bit_val = (bv->data[src_byte] >> src_bit) & 1;

        if (bit_val)
            bv->data[dst_byte] |= (1 << dst_bit);
        else
            bv->data[dst_byte] &= ~(1 << dst_bit);
    }

    size_t byte_index = index / 8;
    size_t bit_index  = index % 8;

    if (value)
        bv->data[byte_index] |= (1 << bit_index);
    else
        bv->data[byte_index] &= ~(1 << bit_index);

    bv->length++;
}
