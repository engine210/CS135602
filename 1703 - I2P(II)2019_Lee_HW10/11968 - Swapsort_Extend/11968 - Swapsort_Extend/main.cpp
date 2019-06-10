//
//  main.cpp
//  11968 - Swapsort_Extend
//
//  Created by engine210 on 2019/6/7.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"

int main()
{
    State s;// = {2, 1, 3};
    int e;
    while (cin >> e) { // press Ctrl + Z to end the input
        s.push_back(e);
    }
    SwapSort prob1(s);
    prob1.solve(4);
    prob1.show_solutions();
    cout << "\n";
}

