#ifndef WK_VECTOR_H
#define WK_VECTOR_H

namespace wk {

template <typename T>
class Vector {
private:
    T** array;
    int size;

public:
    Vector(T** startingArray, int startingSize);

    T* get(int index);
    void push(T* element);
    void remove(int index);

    T* find(bool (*finder)(T*));
    Vector<T> filter(bool (*filter)(T*));
    void sort(bool (*sorter)(T*, T*));

    int getSize();
};

}

#endif