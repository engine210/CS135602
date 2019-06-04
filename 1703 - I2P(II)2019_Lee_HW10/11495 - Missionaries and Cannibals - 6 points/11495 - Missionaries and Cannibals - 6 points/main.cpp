//
//  main.cpp
//  11495 - Missionaries and Cannibals - 6 points
//
//  Created by engine210 on 2019/5/31.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "function.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    int X, Y; //Number of missionaries and cannibals
    cin >> X >> Y;
    Crossing p({X, Y});
    p.solve();
    p.show_solutions();
}
