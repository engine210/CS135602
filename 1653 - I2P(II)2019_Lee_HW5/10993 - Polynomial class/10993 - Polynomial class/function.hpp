//
//  function.hpp
//  10993 - Polynomial class
//
//  Created by engine210 on 2019/4/25.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>

class Polynomial {
    
public:
    Polynomial();
    Polynomial(const int , const int [51]);
    Polynomial add( const Polynomial) const; // add function
    Polynomial subtract( const Polynomial ) const; // subtract function
    Polynomial multiplication( const Polynomial ) const; // multiplication function
    void output() const;
private:
    int coefficients[101]; // integer coefficients
    int greatestPower; // integer greatestPower
}; // end class Polynomial

#endif /* function_hpp */
