#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "bitVector.h"
// тест создание битового вектора
void test_create_bitVector(void)
{
    bitVector *bv = create_bitVector(20);

    assert(bv != NULL);
    assert(bv->length == 0);
    assert(bv->capacity == 20);
    assert(bv->data != NULL);

    // проверяем, что все биты = 0
    for (size_t i = 0; i < 20; i++) {
        size_t byte = i / 8;
        size_t bit  = i % 8;
        assert((bv->data[byte] & (1 << bit)) == 0);
    }

    free_bitVector(bv);

    printf("✔ test_create_bitVector passed\n");
}
// тест увеличение битового вектора
void test_reserve_bitVector(void)
{
    bitVector *bv = create_bitVector(20);
    reserve_bitVector(bv,100);
    assert(bv->capacity == 100);
    free_bitVector(bv);
    printf("✔ test_reserve_bitVector passed\n");
}
//тест добавление элемента в конец vectora
void test_bit_append(void){
    bitVector *bv = create_bitVector(20);
    for(size_t i = 0;i < 20;i++){
        bit_append(bv,i % 2);
    }
    assert(bv->length == 20);
    free_bitVector(bv);
    printf("✔ test_bit_append passed\n");
}
// тест очистка битового вектора
void test_clear_bitVector(void){
    bitVector *bv = create_bitVector(20);
    for(size_t i = 0;i < 20;i++){
        bit_append(bv,i % 2);
    }
    assert(bv->length == 20);
    clear_bitVector(bv);
    assert(bv->length == 0);
    free_bitVector(bv);
    printf("✔ test_clear_bitVector passed\n");
}
//тест удаление элемента из вектора
void test_bit_erase(void){
    bitVector *bv = create_bitVector(20);
    for(size_t i = 0;i < 20;i++){
        bit_append(bv,i % 2);
    }
    assert(bv->length == 20);
    bit_erase(bv,10);
    assert(bv->length == 19);
    free_bitVector(bv);
    printf("✔ test_bit_erase passed\n");
}
//тест добавление элемента в вектор
void test_bit_insert(void){
    bitVector *bv = create_bitVector(20);
    for(size_t i = 0;i < 20;i++){
        bit_append(bv,i % 2);
    }
    assert(bv->length == 20);
    bit_insert(bv,10,1);
    assert(bv->length == 21);
    free_bitVector(bv);
    printf("✔ test_bit_insert passed\n");
}
//тест установки значения бита в векторе
void test_bit_set(void){
    bitVector *bv = create_bitVector(20);
    for(size_t i = 0;i < 20;i++){
        bit_append(bv,i % 2);
    }
    assert(bv->length == 20);
    bit_set(bv,10,1);
    assert(bit_get(bv,10) == 1);
    free_bitVector(bv);
    printf("✔ test_bit_set passed\n");
}
//тест получения значения бита из вектора
void test_bit_get(void){
    bitVector *bv = create_bitVector(20);
    for(size_t i = 0;i < 20;i++){
        bit_append(bv,i % 2);
    }
    assert(bv->length == 20);
    assert(bit_get(bv,10) == 0);
    free_bitVector(bv);
    printf("✔ test_bit_get passed\n");
}
//тест извлечения значения бита из вектора
void test_bit_pop(void){
    bitVector *bv = create_bitVector(20);
    for(size_t i = 0;i < 20;i++){
        bit_append(bv,i % 2);
    }
    assert(bv->length == 20);
    bit_pop(bv);
    assert(bv->length == 19);
    free_bitVector(bv);
    printf("✔ test_bit_pop passed\n");
}

int main(void)
{
    test_create_bitVector();
    test_reserve_bitVector();
    test_bit_append();
    test_clear_bitVector();
    test_bit_erase();
    test_bit_insert();
    test_bit_set();
    test_bit_get();
    test_bit_pop();

    printf("\n✅ ALL TESTS PASSED\n");
    return 0;
}
