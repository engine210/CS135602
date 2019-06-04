//
//  main.cpp
//  9416 - Lexicographic Order
//
//  Created by engine210 on 2019/5/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    priority_queue<string, vector<string>, greater<string>> q;
    string name;
    int N;
    
    freopen("9416_sampleIn.txt", "r", stdin);
    
    cin >> N;
    while (N) {
        for (int i = 0; i < N; i++) {
            cin >> name;
            q.push(name);
        }
        for (int i = 0; i < N; i++) {
            cout << q.top() << endl;
            q.pop();
        }
        cout << endl;
        cin >> N;
    }
    
    return 0;
}

