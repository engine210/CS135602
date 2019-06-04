//
//  main.cpp
//  9328 - Queueing(I)
//
//  Created by engine210 on 2019/5/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    queue<string> q;
    string cmd, name;
    
    freopen("9328_sampleIn.txt", "r", stdin);
    
    while (cin >> cmd) {
        if (cmd == "Push") {
            cin >> name;
            q.push(name);
        }
        else if (cmd == "Pop" && !q.empty()) {
            q.pop();
        }
        else if (cmd == "Front"){
            if (q.empty()) {
                cout << "empty" << endl;
            }
            else {
                cout << q.front() << endl;
            }
        }
    }
    
    return 0;
}
