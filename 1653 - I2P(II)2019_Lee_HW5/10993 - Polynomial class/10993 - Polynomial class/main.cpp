//
//  main.cpp
//  10993 - Polynomial class
//
//  Created by engine210 on 2019/4/25.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "function.hpp"
using namespace std;

int main()
{
    int greatestPower1, greatestPower2;
    int coefficient1[51], coefficient2[51];
    Polynomial ans;
    
    cin>>greatestPower1;
    for(int i = greatestPower1 ; i >= 0; i--)
    {
        cin>>coefficient1[i];
    }
    cin>>greatestPower2;
    for(int i = greatestPower2 ; i >= 0 ; i--)
    {
        cin>>coefficient2[i];
    }
    Polynomial a(greatestPower1, coefficient1), b(greatestPower2, coefficient2);
    
    ans = a.add( b );
    ans.output();
    cout << endl;
    
    ans = a.subtract( b );
    ans.output();
    cout << endl;
    
    ans = a.multiplication( b );
    ans.output();
    cout << endl;
    
} // end main
