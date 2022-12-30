#include "LinkedHashMap.h"
#include <iostream> 

int main() {
    std::cout << "before\n";
    LinkedHashMap<int, int> container; 
    std::cout << "after\n";
    std::cout << "size:" << container.Size();
    //container[5] = "Dog";
    //std::cout << container[5];
    return 0;
}