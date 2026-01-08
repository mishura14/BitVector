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

int main(void)
{
    test_create_bitVector();
    test_reserve_bitVector();

    printf("\n✅ ALL TESTS PASSED\n");
    return 0;
}
