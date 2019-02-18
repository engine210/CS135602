//
//  main.c
//  10222 - moocHW7b
//
//  Created by engine210 on 2019/2/9.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #define ONLINE_JUDGE

/*
 struct for product items
 */
typedef struct _Product {
    char name[51];
    float price;
    float review;
    int  num_reviews;
} Product;

int my_strcmp(const char *s1, const char *s2)
{
    /* your code here */
    int i = 0;
    while (s1[i] != ' ' && s2[i] != ' ') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}

int compare_name(const void *a, const void *b)
{
    /* your code here */
    const char* pa = (const char*) a;
    const char* pb = (const char*) b;
    return my_strcmp(pa, pb);
}

int compare(const void *a, const void *b) {
    Product *ia, *ib;
    
    ia = *(Product **)a;
    ib = *(Product **)b;
    /*
     Can I do in this way?
     ia = (Product*) a;
     ib = (Product*) b;
     */
    /* your code here */
    if (my_strcmp(ia->name, ib->name) == 0) {
        if (ia->review > ib->review) {
            return 0;
        }
        else if (ia->review < ib->review) {
            return 1;
        }
        else {
            return ia->price - ib->price;
        }
    }
    else {
        return my_strcmp(ia->name, ib->name);
    }
    
}

void show_product(Product *item)
{
    printf("%s, ", item->name);
    printf("$%.2f, ", item->price);
    printf("%.1f\n", item->review);
}

int main(void)
{
    Product **items;
    int i, j;
    int ndata, nqueries;
    Product **filtered;
    float lower, upper;
    int num;
    
    scanf("%d", &ndata);
    while (getchar() !='\n');
    
    items = (Product**) malloc(sizeof(Product*) * ndata);
    
    for (i=0; i<ndata; i++) {
        items[i] = (Product*) malloc(sizeof(Product));
        fgets(items[i]->name, 31, stdin);
        items[i]->name[strlen(items[i]->name)-1] = '\0';
        scanf("%f", &items[i]->price);
        scanf("%f", &items[i]->review);
        scanf("%d", &items[i]->num_reviews);
        while (getchar() !='\n');
    }
    
    scanf("%d", &nqueries);
    //while (getchar() != '\n');
    
    qsort(items, ndata, sizeof(Product *), compare);
    
    filtered = (Product**) malloc(sizeof(Product*) * ndata);
    for (i = 0; i < nqueries; i++) {
        scanf("%f%f", &lower, &upper);
        printf("%.2f<=price<=%.2f\n", lower, upper);
        
        /* your code here */
        for (j = 0; j < ndata; j++) {
            if (items[j]->price >= lower && items[j]->price <= upper) {
                show_product(items[j]);
            }
        }
    }
    
    for (i=0; i<ndata; i++) {
        free(items[i]);
    }
    free(items);
    free(filtered);
    return 0;
}
