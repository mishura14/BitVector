# реализация bitVector на C
Для сборки библиотеки нужно
создать папку build
```
mkdir build
```
нужно в нее перейти 
```
cd build
```
и выполнить команды
```
cmake ..
cmake --build .
```
В моем bitvector реализовны следующие методы:
```c

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

// фукция erase
void bit_erase(bitVector *bv, size_t index);

// функция insert
void bit_insert(bitVector *bv, size_t index, uint8_t value);

//функция set
void bit_set(bitVector *bv, size_t index, uint8_t value);

// функция get
uint8_t bit_get(const bitVector *bv, size_t index);

// функция pop
uint8_t bit_pop(bitVector *bv);

```
они реализованы с помощью битовых операций и сдвигов.
Это базовый набор методов для работы с вектором.
