//
//  function.cpp
//  11410 - Implement a vector 2
//
//  Created by engine210 on 2019/5/11.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"
#include <iostream>

oj::Vector::Vector() {
    begin_ = nullptr;
    end_ = nullptr;
    last_ = nullptr;
}

void oj::Vector::pop_back() {
    if (size()) {
        last_--;
    }
}

void oj::Vector::push_back(data_t val) {
    if (size() == capacity()) {
        reserve(std::max(capacity()+1, capacity()*3));
    }
    *last_ = val;
    last_++;
}

size_t oj::Vector::size() const {
    return last_ - begin_;
}

size_t oj::Vector::capacity() const {
    return end_ - begin_;
}

void oj::Vector::insert(std::size_t pos, std::size_t count, data_t val) {
    if (size() + count > capacity()) {
        reserve(std::max(static_cast<size_t>(capacity()*1.5), capacity()+count));
    }
    std::copy_backward(begin_+pos, last_, last_+count);
    std::fill(begin_+pos, begin_+pos+count, val);
    /*
    for (auto i = size() + count - 1; i >= pos + count; i--) {
        begin_[i] = begin_[i-count];
    }
    for (auto i = pos; i < pos+count; i++) {
        begin_[i] = val;
    }
    */
    last_ += count;
}

void oj::Vector::reserve(std::size_t new_capacity) {
    if (new_capacity > capacity()) {
        size_t oldSize = size();
        pointer newbegin = new Int[new_capacity];
        end_ = newbegin + new_capacity;
        std::copy(begin_, begin_+oldSize, newbegin);
        /*
        int i;
        for (i = 0; i < oldSize; i++) {
            newbegin[i] = begin_[i];
        }
        */
        delete [] begin_;
        begin_ = newbegin;
        last_ = begin_ + oldSize;
    }
}

void oj::Vector::resize(std::size_t new_size) {
    size_t oldCapacity = capacity();
    size_t oldSize = size();
    if (new_size > oldCapacity) {
        reserve(new_size);
        /*
        for (auto i = oldSize; i < new_size; i++) {
            begin_[i] = 0;
        }
         */
        last_ = begin_ + new_size;
        std::fill(begin_+oldSize, last_, 0);
    }
    else if (new_size > oldSize) {
        size_t oldSize = size();
        /*
        for (auto i = oldSize; i < new_size; i++) {
            begin_[i] = 0;
        }
         */
        last_ = begin_ + new_size;
        std::fill(begin_+oldSize, last_, 0);
    }
    else if (new_size < oldSize){
        last_ -= oldSize - new_size;
    }
}

oj::Vector::~Vector() {
    delete [] begin_;
}
