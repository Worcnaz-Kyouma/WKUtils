#ifndef WK_UTILS_H
#define WK_UTILS_H

namespace wk {

class Utils {
public:
    template <typename T>
    static T** createArrayCopy(T** source, int numberOfCopying);

    template <typename T>
    static T** createArrayCopy(T** source, int numberOfCopying, T** destination);

    template <typename T>
    static T** createArrayCopyWithFilter(T** source, int numberOfCopying, bool (*filter)(T*));

    template <typename T>
    static T** addNewElementToArray(T** source, int sourceSize, T* newElement);
};

}

#endif