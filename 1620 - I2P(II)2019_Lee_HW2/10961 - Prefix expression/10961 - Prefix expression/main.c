//
//  main.c
//  10961 - Prefix expression
//
//  Created by engine210 on 2019/3/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>

int cal() {
    char c = getchar();
    if (c == ' ') {
        c = getchar();
    }
    if (c == '+') {
        return cal() + cal();
    }
    else if (c == '-') {
        return cal() - cal();
    }
    else {
        ungetc(c, stdin);
        int ans;
        scanf("%d", &ans);
        return ans;
    }
}

int main(int argc, const char * argv[]) {
    //getchar();
    printf("%d", cal());
    
    return 0;
}

