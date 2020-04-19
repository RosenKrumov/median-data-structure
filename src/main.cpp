#include "median_structure.h"

#include <iostream>

int main () {
    MedianStructure m;
    for (int n : {10, 4, 2, 4}) {
        m.addNumber(n);
        std::cout << "lower - " << m.lowerContainerSize() << std::endl;
        std::cout << "higher - " << m.higherContainerSize() << std::endl;
    }


    std::cout << m.getMedian() << std::endl;
}