#include "utils.hpp"

namespace wk {

template <typename T>
T** Utils::createArrayCopy(T** source, int numberOfCopying) {
    T** destination = new T*[numberOfCopying];

    return Utils::createArrayCopy(source, numberOfCopying, destination);
}

template <typename T>
T** Utils::createArrayCopy(T** source, int numberOfCopying, T** destination) {
    for(int c=0; c<numberOfCopying; c++) {
        T copiedElement = *source[c];
        destination[c] = &copiedElement;
    }

    return destination;
}

template <typename T>
T** Utils::createArrayCopyWithFilter(T** source, int numberOfCopying, bool (*filter)(T*)) {
    T** newArray = new T*[numberOfCopying];

    int newArrayIndex = 0;
    for(int c=0; c<numberOfCopying; c++) {
        bool isCopy = filter(source[c]);
        if(!isCopy) {
            newArray[c] = nullptr;
        } else {
            T copiedElement = *source[c];
            newArray[c] = &copiedElement;
        }
    }

    return newArray;
}

template <typename T>
T** Utils::addNewElementToArray(T** source, int sourceSize, T* newElement) {
    T** newArray = new T*[sourceSize+1];

    Utils::createArrayCopy(source, sourceSize, newArray);

    newArray[sourceSize] = newElement;

    return newArray;
}

}