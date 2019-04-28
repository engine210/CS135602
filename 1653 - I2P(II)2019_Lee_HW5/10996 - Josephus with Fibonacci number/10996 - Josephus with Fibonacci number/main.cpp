//
//  main.cpp
//  10996 - Josephus with Fibonacci number
//
//  Created by engine210 on 2019/4/23.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include "function.hpp"
using namespace std;
int main(){
    int numofpeople;
    
    while(cin>>numofpeople){
        Josephus Jose(numofpeople);
        int survival = Jose.kill();
        cout<<survival<<endl;
    }
}

