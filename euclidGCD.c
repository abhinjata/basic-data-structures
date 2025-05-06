#include <stdio.h>

int euclid(int a, int b){

    if(a == 0){

        return b;
    }


    return euclid(b%a, a);
}

int main(void) {
    
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    int gcd = euclid(a, b);

    printf("%d", gcd);
}