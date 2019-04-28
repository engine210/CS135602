//
//  function.cpp
//  11933 - Vector Dot
//
//  Created by engine210 on 2019/4/28.
//  Copyright © 2019 engine210. All rights reserved.
//

//remember to change function.hpp to function.h when submit to inline judge
#include "function.hpp"

const int Vector::operator[](int index) const {
    return v[index];
}

int Vector::operator*(const Vector &a) {
    int ans = 0;
    for (int i = 0; i < v_size; i++) {
        ans += v[i] * a[i];
    }
    return ans;
}
