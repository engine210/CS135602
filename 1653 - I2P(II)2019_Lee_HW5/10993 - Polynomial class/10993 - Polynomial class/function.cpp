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

Polynomial::Polynomial(const int greatestPower, const int coefficients[]) {
    this->greatestPower = greatestPower;
    memcpy(this->coefficients, coefficients, sizeof(int) * (greatestPower + 1));
}

Polynomial Polynomial::add(const Polynomial summand) const {
    int greatestPower;
    int i;
    int coefficients[101];
    if (this->greatestPower >= summand.greatestPower) {
        greatestPower = this->greatestPower;
        for (i = 0; i <= summand.greatestPower; i++) {
            coefficients[i] = this->coefficients[i] + summand.coefficients[i];
        }
        for (; i <= this->greatestPower; i++) {
            coefficients[i] = this->coefficients[i];
        }
    }
    else {
        greatestPower = summand.greatestPower;
        for (i = 0; i <= this->greatestPower; i++) {
            coefficients[i] = this->coefficients[i] + summand.coefficients[i];
        }
        for (; i <= summand.greatestPower; i++) {
            coefficients[i] = summand.coefficients[i];
        }
    }
    
    Polynomial sum(greatestPower, coefficients);
    return sum;
}

Polynomial Polynomial::subtract(const Polynomial subtrahend) const {
    
    int greatestPower;
    int i;
    int coefficients[101];
    
    if (this->greatestPower >= subtrahend.greatestPower) {
        greatestPower = this->greatestPower;
        for (i = 0; i <= subtrahend.greatestPower; i++) {
            coefficients[i] = this->coefficients[i] - subtrahend.coefficients[i];
        }
        for (; i <= this->greatestPower; i++) {
            coefficients[i] = this->coefficients[i];
        }
    }
    else {
        greatestPower = subtrahend.greatestPower;
        for (i = 0; i <= this->greatestPower; i++) {
            coefficients[i] = this->coefficients[i] - subtrahend.coefficients[i];
        }
        for (; i <= subtrahend.greatestPower; i++) {
            coefficients[i] = -subtrahend.coefficients[i];
        }
    }
    Polynomial ans(greatestPower, coefficients);
    return ans;
}

Polynomial Polynomial::multiplication(const Polynomial multiplier) const {
    int greatestPower;
    int i, j;
    int coefficients[101];
    greatestPower = this->greatestPower + multiplier.greatestPower;
    
    for (int i = 0; i < 101; i++) {
        coefficients[i] = 0;
    }
    //memset(coefficients, 0, sizeof(coefficients));
    for (i = 0; i <= this->greatestPower; i++) {
        for (j = 0; j <= multiplier.greatestPower; j++) {
            coefficients[i+j] += this->coefficients[i] * multiplier.coefficients[j];
        }
    }
    
    Polynomial ans(greatestPower, coefficients);
    return ans;
}

void Polynomial::output() const {
    int i;
    for (i = greatestPower; i > 0; i--) {
        cout << coefficients[i] << " ";
    }
    cout << coefficients[i];
}
