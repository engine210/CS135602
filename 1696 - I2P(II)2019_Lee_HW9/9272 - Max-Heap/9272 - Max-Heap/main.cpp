//
//  main.cpp
//  9272 - Max-Heap
//
//  Created by engine210 on 2019/5/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    priority_queue<int32_t> s;
    string cmd;
    int32_t num;
    
    freopen("9272_sampleIn.txt", "r", stdin);
    
    while (cin >> cmd) {
        if (cmd == "PUSH") {
            cin >> num;
            s.push(num);
        }
        else if (cmd == "POP" && !s.empty()) {
            s.pop();
        }
        else if (cmd == "TOP"){
            if (s.empty()) {
                cout << "Null" << endl;
            }
            else {
                cout << s.top() << endl;
            }
        }
    }
    
    return 0;
}
