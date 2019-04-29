//
//  main.cpp
//  10922 - Insertion Sort
//
//  Created by engine210 on 2019/4/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>

using namespace std;

int insertionSort(int n, int* arr) {
    int swapTimes = 0;
    int temp;
    
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swapTimes++;
            }
        }
    }
    
    return swapTimes;
}

int main(int argc, const char * argv[]) {
    
    int T, N;
    int arr[1000000];
    int total = 0;
    
    cin >> T;
    
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        total += insertionSort(N, arr);
    }
    
    cout << total << endl;
    
    return 0;
}
