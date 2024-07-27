#include "iostream"
#include "wkutils.hpp"

int main() {
    wk::Vector<int> vector;
    

    vector.push(3);

    int *value = vector.get(0);

    std::cout << *value << std::endl;
}