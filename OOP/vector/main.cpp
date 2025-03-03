#include <iostream>

using namespace std;

struct vector_t {
    int size;
    int capacity;
    int* array;
};

vector_t* create() {
    vector_t* v = new vector_t;
    v->size = 0;
    v->capacity = 2;
    v->array = new int[v->capacity];
    return v;
}

void free_vector(vector_t* v) {
    delete[] v->array;
    delete v;
}

void resize(vector_t* v) {//realloc
    v->capacity *= 2;
    int* newArray = new int[v->capacity];
    for (int i = 0; i < v->size; ++i) {
        newArray[i] = v->array[i];
    }
    delete[] v->array;
    v->array = newArray;
}

void add(vector_t* v, int num) {
    if (v->size == v->capacity) {
        resize(v);
    }
    v->array[v->size++] = num;
}

int remove_back(vector_t* v) {
    return v->array[--v->size];
}

void print(vector_t* v) {
    cout << v->size << "\n";
    cout << v->capacity << "\n";

    for (int i = 0; i < v->size; i++) {
        if (i != v->size - 1) {
            cout << v->array[i] << ", ";
        } else {
            cout << v->array[i];
        }
    }
    cout << "\n";
}

int main() {
    vector_t* vector = create();
    print(vector);

    add(vector, 10);
    add(vector, 20);
    add(vector, 30);

    print(vector);

    int a = remove_back(vector);
    cout << "Removed: " << a << "\n";
    print(vector);

    free_vector(vector);
    return 0;
}
