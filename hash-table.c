#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int key;
    int value;
} Entry;

Entry* hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);

    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;

    hashTable[index] = newEntry;
}

int search(int key) {
    int index = hashFunction(key);

    if (hashTable[index] != NULL && hashTable[index]->key == key) {
        return hashTable[index]->value;
    }

    return -1; // Retorna -1 se a chave não for encontrada
}

int main() {
    insert(1, 10);
    insert(5, 20);
    insert(11, 30);
    insert(15, 40);

    int value = search(5);
    if (value != -1) {
        printf("Valor encontrado: %d\n", value);
    } else {
        printf("Chave não encontrada.\n");
    }

    return 0;
}

