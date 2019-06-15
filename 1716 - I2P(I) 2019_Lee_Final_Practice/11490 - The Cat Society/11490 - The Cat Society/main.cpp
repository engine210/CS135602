//
//  main.cpp
//  11490 - The Cat Society
//
//  Created by engine210 on 2019/6/13.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef struct cat {
    string name;
    int occupation;
    int age;
    bool operator < (const cat& rhs) const {
        if (occupation < rhs.occupation) {
            return false;
        }
        else if (occupation > rhs.occupation){
            return true;
        }
        else {
            if (occupation == 5) {
                if (age < rhs.age) {
                    return false;
                }
                else if (age > rhs.age){
                    return true;
                }
                else {
                    return name > rhs.name;
                }
            }
            else {
                if (age > rhs.age) {
                    return false;
                }
                else if (age < rhs.age){
                    return true;
                }
                else {
                    return name > rhs.name;
                }
            }
        }
    }
    
} cat;

int main(int argc, const char * argv[]) {
    
    int N, M;
    string occupation;
    priority_queue<cat> list;
    map<string, int> Occupation = {
        {"elder", 1},
        {"nursy", 2},
        {"kitty", 3},
        {"warrior", 4},
        {"apprentice", 5},
        {"medicent", 6},
        {"deputy", 7},
        {"leader", 8}
    };
    cat in;
    
    //freopen("11490_sampleIn.txt", "r", stdin);
    
    
    while(cin >> N >> M) {
        while (N--) {
            cin >> in.name >> occupation >> in.age;
            in.occupation = Occupation[occupation];
            list.push(in);
        }
        
        while (M-- && !list.empty()) {
            cout << list.top().name << "\n";
            list.pop();
        }
        priority_queue<cat>().swap(list);
    }
    
    return 0;
}


