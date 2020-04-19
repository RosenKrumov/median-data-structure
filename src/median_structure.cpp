#include "median_structure.h"

void MedianStructure::addNumber(double num) {
    if (lower_numbers.empty() && higher_numbers.empty()) {
        // first time, push in lower
        lower_numbers.push(num);
    } else if (num < getMedian()) {
        // push lower-than-median numbers in lower container
        lower_numbers.push(num);
        // keep sizes consistent
        if(lower_numbers.size() > higher_numbers.size() + 1) {
            higher_numbers.push(lower_numbers.top());
            lower_numbers.pop();
        }
    } else if (num > getMedian()) {
        // push higher-than-median numbers in higher container
        higher_numbers.push(num);
        // keep sizes consistent
        if(higher_numbers.size() > lower_numbers.size() + 1) {
            lower_numbers.push(higher_numbers.top());
            higher_numbers.pop();
        }
    } else if (num == getMedian()) {
        // if num is equal to median, push to smaller container, otherwise to lower
        if (lower_numbers.size() <= higher_numbers.size()) {
            lower_numbers.push(num);
        } else if (lower_numbers.size() > higher_numbers.size()) {
            higher_numbers.push(num);
        }
    }
}

auto MedianStructure::getMedian() -> double {
    if (lower_numbers.empty() && higher_numbers.empty()) return 0;

    // median is the top of the bigger container, otherwise the mean of both
    if (lower_numbers.size() > higher_numbers.size()) {
        return lower_numbers.top();
    } else if (lower_numbers.size() < higher_numbers.size()) {
        return higher_numbers.top();
    } else {
        return (lower_numbers.top() + higher_numbers.top()) / 2;
    }
}

auto MedianStructure::lowerContainerSize() -> int {
    return lower_numbers.size();
}

auto MedianStructure::higherContainerSize() -> int {
    return higher_numbers.size();
}