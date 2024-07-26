#include "vector.hpp"

namespace wk {
template <typename T>
Vector<T>::Vector(T** startingArray, int startingSize){
    this->array = new T*[startingSize];
}

} 
