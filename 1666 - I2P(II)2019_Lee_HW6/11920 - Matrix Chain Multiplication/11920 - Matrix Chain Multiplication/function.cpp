//
//  function.cpp
//  11920 - Matrix Chain Multiplication
//
//  Created by engine210 on 2019/4/27.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"
#include <string.h>

Matrix Matrix::operator*(const Matrix &a) const {
    Matrix product(size_row, a.size_col);
    for (int i = 0; i < size_row; i++) {
        for (int j = 0; j < a.size_col; j++) {
            int sum = 0;
            for (int k = 0; k < size_col; k++) {
                sum += arr[i][k] * a.arr[k][j];
            }
            product.arr[i][j] = sum;
        }
    }
    return product;
}

Matrix Matrix::operator=(const Matrix &a) {
    // delete the original array
    for (int i = 0; i < size_row; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    
    // copy a new array
    size_row = a.size_row;
    size_col = a.size_col;
    arr = new int* [size_row];
    for (int i = 0; i < size_row; i++) {
        arr[i] = new int[size_col];
        memcpy(arr[i], a.arr[i], sizeof(int) * (size_col + 1));
    }
    
    return *this;
}

Matrix MatrixChain::calc(int l, int r) const {
    if (l == r-1) {
        return *arr[l];
    }
    else {
        return (*arr[l]) * calc(l+1, r);
    }
}
