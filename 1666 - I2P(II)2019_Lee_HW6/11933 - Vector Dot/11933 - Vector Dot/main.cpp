//
//  main.cpp
//  11933 - Vector Dot
//
//  Created by engine210 on 2019/4/28.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"
#include <string>
int main() {
    int m, size;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::string op;
        std::cin >> op >> size;
        Vector A(size);
        Vector B(size);
        A.read();
        B.read();
        if (op == "DOT")
            std::cout << A*B  << ' ' << '\n';
    }
    return 0;
}
