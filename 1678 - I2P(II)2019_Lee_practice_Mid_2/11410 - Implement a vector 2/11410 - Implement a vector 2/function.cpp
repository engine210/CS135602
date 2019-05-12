//
//  function.cpp
//  11410 - Implement a vector 2
//
//  Created by engine210 on 2019/5/11.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"

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
    size_t oldCapacity = capacity();
    size_t oldSize = size();
    if (oldCapacity == oldSize) {
        pointer newbegin;
        if (capacity() + 1 > capacity() * 3) {
            newbegin = new Int[oldCapacity+1];
            end_ = newbegin + oldCapacity + 1;
        }
        else {
            newbegin = new Int[oldCapacity*3];
            end_ = newbegin + oldCapacity*3;
        }
        int i;
        for (i = 0; i < oldCapacity; i++) {
            newbegin[i] = begin_[i];
        }
        newbegin[i] = val;
        delete [] begin_;
        begin_ = newbegin;
        last_ = begin_ + oldCapacity + 1;
    }
    else {
        *last_ = val;
        last_++;
    }
}

size_t oj::Vector::size() const {
    return last_ - begin_;
}

size_t oj::Vector::capacity() const {
    return end_ - begin_;
}

void oj::Vector::insert(std::size_t pos, std::size_t count, data_t val) {
    size_t oldCapacity = capacity();
    size_t oldSize = size();
    if (oldSize + count > oldCapacity) {
        pointer newbegin;
        if (oldCapacity * 1.5 > oldCapacity + count) {
            newbegin = new Int[static_cast<int>(oldCapacity * 1.5)];
            end_ = newbegin + static_cast<int>(oldCapacity * 1.5);
        }
        else {
            newbegin = new Int[oldCapacity + count];
            end_ = newbegin + oldCapacity + count;
        }
        
        int i, j;
        for (i = 0; i <= pos; i++) {
            newbegin[i] = begin_[i];
        }
        j = i;
        for (; i <= pos + count; i++) {
            newbegin[i] = val;
        }
        for (; j < oldSize; j++, i++) {
            newbegin[i] = begin_[j];
        }
        delete [] begin_;
        begin_ = newbegin;
        last_ = begin_ + oldSize + count;
    }
    else {
        for (auto i = oldSize + count - 1; i >= pos + count; i--) {
            begin_[i] = begin_[i - count];
        }
        for (auto i = pos; i < pos + count; i++) {
            begin_[i] = val;
        }
        last_ = begin_ + oldSize + count;
    }
}

void oj::Vector::reserve(std::size_t new_capacity) {
    if (new_capacity > capacity()) {
        size_t oldCapacity = capacity();
        size_t oldSize = size();
        pointer newbegin = new Int[new_capacity];
        end_ = newbegin + new_capacity;
        int i;
        for (i = 0; i < oldCapacity; i++) {
            newbegin[i] = begin_[i];
        }
        delete [] begin_;
        begin_ = newbegin;
        last_ = begin_ + oldSize;
    }
}

void oj::Vector::resize(std::size_t new_size) {
    size_t oldCapacity = capacity();
    size_t oldSize = size();
    if (new_size > oldCapacity) {
        pointer newbegin = new Int[new_size];
        end_ = newbegin + new_size;
        int i;
        for (i = 0; i < oldCapacity; i++) {
            newbegin[i] = begin_[i];
        }
        for (; i < new_size; i++) {
            newbegin[i] = 0;
        }
        delete [] begin_;
        begin_ = newbegin;
        last_ = end_;
    }
    else if (new_size > oldSize) {
        for (int i = 0; i < new_size - oldSize; i++) {
            *last_ = 0;
            last_++;
        }
    }
    else if (new_size < oldSize){
        last_ -= oldSize - new_size;
    }
}

oj::Vector::~Vector() {
    delete [] begin_;
}
