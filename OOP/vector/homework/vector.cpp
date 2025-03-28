#include <iostream>

using namespace std;

const int VECTOR_ERROR = 0;
//error

struct vector_t
{
    int *data;
    size_t size;
    size_t capacity;
} typedef Vector;

struct vector_t *initVector();

void pushBack(Vector *v, int number);

void resize(Vector *v)
{
    v->capacity *= 2;
    int *tmp = new int[v->capacity];
    for (size_t i = 0; i < v->size; i++)
    {
        tmp[i] = v->data[i];
    }
    delete[] v->data;
    v->data = tmp;
}

//////////////////////////////
// Vector's size:
// Vector's capacity:
// Vector's data:
//////////////////////////////
void print(Vector *v)
{
    cout << "Size: " << v->size << endl;
    cout << "Capacity: " << v->capacity << endl;
    cout << "Data: ";

    if (v->size > 0)
        cout << v->data[0];
    for (size_t i = 1; i < v->size; i++)
    {
        cout << " " << v->data[i];
    }
}

/**
 * @brief Returns the element at the provided index
 *
 * @param v
 * @param index
 * @return int
 */
int at(Vector *v, int index)
{
    if (index < 0 || index >= v->size)
    {
        return VECTOR_ERROR;
    }
    return v->data[index];
}

/**
 * @brief Pops the last element of the vector
 *
 * @param v
 * @return int if successful, ERROR - if not
 */
int pop(Vector *v)
{
    if (v->size == 0)
    {
        return VECTOR_ERROR;
    }
    int value = v->data[v->size - 1];
    v->size--;
    return value;
}

/**
 * @brief Frees the memory allocated by the vector
 *
 * @param v
 */
void destroy(Vector *v)
{
    if (v != NULL)
    {
        delete[] v->data;
        delete v;
    }
}

/**
 * @brief Adds an element in the beginning of the vector
 *
 * @param v
 * @param number
 */
void pushFront(Vector *v, int number)
{
    if (v->size == v->capacity)
    {
        resize(v);
    }
    
    for (size_t i = v->size; i > 0; i--)
    {
        v->data[i] = v->data[i - 1];
    }
    
    v->data[0] = number;
    v->size++;
}

/**
 * @brief Pops the first element of the vector
 *
 * @param v
 * @return int if successful, ERROR - if not
 */
int popFront(Vector *v)
{
    if (v->size == 0)
    {
        return VECTOR_ERROR;
    }
    
    int value = v->data[0];
    
    for (size_t i = 0; i < v->size - 1; i++)
    {
        v->data[i] = v->data[i + 1];
    }
    
    v->size--;
    return value;
}

/**
 * @brief Inserts an element at a given index
 *
 * @param v
 * @param index
 * @param number
 * @return int 0 if successful, ERROR - if not
 */
int insert(Vector *v, int index, int number)
{
    if (index < 0 || index > v->size)
    {
        return VECTOR_ERROR;
    }
    
    if (v->size == v->capacity)
    {
        resize(v);
    }
    
    for (size_t i = v->size; i > index; i--)
    {
        v->data[i] = v->data[i - 1];
    }
    
    v->data[index] = number;
    v->size++;
    return 0;
}

/**
 * @brief Removes an element at a given index
 *
 * @param v
 * @param index
 * @param number
 * @return int the number if usccesful, ERROR - if not
 */
int remove(Vector *v, int index)
{
    if (index < 0 || index >= v->size)
    {
        return VECTOR_ERROR;
    }
    
    int value = v->data[index];
    
    for (size_t i = index; i < v->size - 1; i++)
    {
        v->data[i] = v->data[i + 1];
    }
    
    v->size--;
    return value;
}

// int main()
// {
//     Vector *v = initVector();
//     // pushBack(v, 2);
//     // pushBack(v, 3);
//     print(v);
//     return 0;
// }

struct vector_t *initVector()
{
    Vector *v = new Vector();
    v->size = 0;
    v->capacity = 2; // 5
    v->data = new int[v->capacity];

    return v;
}

void pushBack(Vector *v, int number)
{
    if (v->size == v->capacity)
    {
        resize(v);
    }
    v->data[v->size++] = number; //++i i++
}