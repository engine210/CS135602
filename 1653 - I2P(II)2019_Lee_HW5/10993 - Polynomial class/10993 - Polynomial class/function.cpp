//
//  function.cpp
//  10993 - Polynomial class
//
//  Created by engine210 on 2019/4/25.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"
#include <stdlib.h>
#include <string.h>

using namespace std;

Polynomial::Polynomial() {
    greatestPower = 0;
}

Polynomial::Polynomial(const int greatestPower, const int cofficients[]) {
    this->greatestPower = greatestPower;
    memcpy(this->coefficients, cofficients, 101);
}

Polynomial Polynomial::add(const Polynomial summand) const {
    int greatestPower;
    int i;
    int cofficients[101];
    if (this->greatestPower >= summand.greatestPower) {
        greatestPower = this->greatestPower;
        for (i = 0; i <= summand.greatestPower; i++) {
            cofficients[i] = this->coefficients[i] + summand.coefficients[i];
        }
        for (; i <= this->greatestPower; i++) {
            cofficients[i] = this->coefficients[i];
        }
    }
    else {
        greatestPower = summand.greatestPower;
        for (i = 0; i <= this->greatestPower; i++) {
            cofficients[i] = this->coefficients[i] + summand.coefficients[i];
        }
        for (; i <= summand.greatestPower; i++) {
            cofficients[i] = summand.coefficients[i];
        }
    }
    
    Polynomial sum(greatestPower, cofficients);
    return sum;
}

Polynomial Polynomial::subtract(const Polynomial subtrahend) const {
    
    int greatestPower;
    int i;
    int cofficients[101];
    
    if (this->greatestPower >= subtrahend.greatestPower) {
        greatestPower = this->greatestPower;
        for (i = 0; i <= subtrahend.greatestPower; i++) {
            cofficients[i] = this->coefficients[i] - subtrahend.coefficients[i];
        }
        for (; i <= this->greatestPower; i++) {
            cofficients[i] = this->coefficients[i];
        }
    }
    else {
        greatestPower = subtrahend.greatestPower;
        for (i = 0; i <= this->greatestPower; i++) {
            cofficients[i] = this->coefficients[i] - subtrahend.coefficients[i];
        }
        for (; i <= subtrahend.greatestPower; i++) {
            cofficients[i] = -subtrahend.coefficients[i];
        }
    }
    Polynomial ans(greatestPower, cofficients);
    return ans;
}

Polynomial Polynomial::multiplication(const Polynomial multiplier) const {
    int greatestPower;
    int i, j;
    int cofficients[101];
    greatestPower = this->greatestPower + multiplier.greatestPower;
    
    memset(cofficients, 0, sizeof(cofficients));
    for (i = 0; i <= this->greatestPower; i++) {
        for (j = 0; j <= multiplier.greatestPower; j++) {
            cofficients[i+j] += this->coefficients[i] * multiplier.coefficients[j];
        }
    }
    
    Polynomial ans(greatestPower, cofficients);
    return ans;
}

void Polynomial::output() const {
    int i, flag = 0;
    for (i = greatestPower; i > 0; i--) {
        if (coefficients[i]) {
            flag = 1;
        }
        if (flag) {
            cout << coefficients[i] << " ";
        }
    }
    cout << coefficients[i];
}
