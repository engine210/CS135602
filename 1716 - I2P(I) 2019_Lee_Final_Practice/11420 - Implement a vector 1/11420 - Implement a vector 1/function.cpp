//
//  function.cpp
//  11420 - Implement a vector 1
//
//  Created by engine210 on 2019/6/13.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"
#include <algorithm>

void oj::Vector::pop_back() {
    if (size()) {
        last_--;
    }
}

void oj::Vector::push_back(value_type val) {
    if (size() == capacity()) {
        reserve(std::max(capacity()+1, capacity()*3));
    }
    *last_ = val;
    last_++;
}

void oj::Vector::reserve(size_type new_capacity) {
    if (new_capacity > capacity()) {
        size_t oldSize = size();
        pointer newbegin = new Int[new_capacity];
        end_ = newbegin + new_capacity;
        std::copy(begin_, last_, newbegin);
        delete [] begin_;
        begin_ = newbegin;
        last_ = begin_ + oldSize;
    }
}

oj::Vector::~Vector() {
    delete [] begin_;
}
