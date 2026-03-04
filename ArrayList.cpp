#include <iostream>

class ArrayList {
private:
    int* data;
    int capacity;
    int size;

    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    ArrayList(int initCap = 10) : capacity(initCap), size(0) {
        data = new int[capacity];
    }

    ~ArrayList() { delete[] data; }

    // INSERÇÃO: O(1) amortizado
    void add(int value) {
        if (size == capacity) resize();
        data[size++] = value;
    }

    // REMOÇÃO: O(1) (sempre do final para ser justo no benchmark)
    void remove() {
        if (size > 0) size--;
    }

    // BUSCA: O(n) (necessário percorrer o array)
    int find(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) return i;
        }
        return -1;
    }

    int getSize() const { return size; }
};
