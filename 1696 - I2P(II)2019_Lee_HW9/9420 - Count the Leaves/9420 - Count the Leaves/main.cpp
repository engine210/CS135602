//
//  main.cpp
//  9420 - Count the Leaves
//
//  Created by engine210 on 2019/5/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    
    set<int> parent, child;
    int N, a, b;
    
    freopen("9420_sampleIn.txt", "r", stdin);
    
    cin >> N;
    while (N) {
        parent.clear();
        child.clear();
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            parent.insert(a);
            child.erase(a);
            if (!parent.count(b)) {
            //if (parent.find(b) == parent.end()) {
                child.insert(b);
            }
        }
        cin >> a;
        cout << child.size() << endl;
        cin >> N;
    }
    return 0;
}
