#include "vector.hpp"
#include "utils.hpp"

namespace wk {

template <typename T>
Vector<T>::Vector() {
    this->array = nullptr;
    this->size = 0;  
}

template <typename T>
Vector<T>::Vector(T** startingArray, int startingSize): 
size(startingSize) {
    this->array = Utils::createArrayCopy<T>(startingArray, startingSize);
}

template <typename T>
T* Vector<T>::get(int index) {
    if(index >= this->size) {
        //Error
    }

    T* element = this->array[index];
    T elementCopy = *element;

    return &elementCopy;
}

template <typename T>
void Vector<T>::push(T* element) {
    T copiedElement = *element;

    delete this->array;

    this->array = Utils::addNewElementToArray(this->array, this->size, &copiedElement);
    
    this->size++;
}

template <typename T>
void Vector<T>::remove(int index) {
    if(this->size < 1) {
        //Error
    }

    T** newArray = new T*[this->size-1];

    int i = 0;
    for(int c=0; c<this->size; c++) {
        if(c == index) continue;

        newArray[i] = this->array[i];
        i++
    }

    this->size--;
}

template <typename T>
T* Vector<T>::find(bool (*finder)(T*)) {
    for(int c=0; c<this->size; c++) {
        T* element = this->array[c];

        bool found = finder(element);
        if(found) return element;
    }

    return nullptr;
}

template <typename T>
Vector<T> Vector<T>::filter(bool (*filter)(T*)) {
    Vector filteredVector;

    for(int c=0; c<this->size; c++) {
        T* element = this->array[c];

        bool found = filter(element);
        if(found) filteredVector.push(element);
    }

    return filteredVector;
}

template <typename T>
void Vector<T>::sort(bool (*sorter)(T*, T*)) {
    for(int c=0; c<this->size-1; c++) {
        T* elementA = this->array[c];
        T* elementB = this->array[c+1];
        
        bool sorted = sorter(elementA, elementB);
        if(!sorted) {
            this->array[c] = elementB;
            this->array[c+1] = elementA;

            c = -1;
        }
    }
}

template <typename T>
int Vector<T>::getSize() {
    return this->size;
}

} 
