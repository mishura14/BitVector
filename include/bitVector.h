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
bitVector *create_bitVector(size_t capacity);

//удаление битового вектора
void free_bitVector(bitVector *bv);

//увеличение битового вектора
void reserve_bitVector(bitVector *bv, size_t new_capacity);

//добавление бита в конец vectora
void bit_append(bitVector *bv, uint8_t value);

// функция clear
void clear_bitVector(bitVector *bv);
