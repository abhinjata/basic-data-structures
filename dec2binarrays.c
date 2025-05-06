#include <stdio.h>

//dec2bin using arrays

int main(void) {

    int n;
    scanf("%d", &n);

    int allBits[32] = {};

    int i = 0;

    while(n > 0){

        allBits[i] = n%2;

        i = i + 1;
        n = n/2;
    }

    for(int j = i-1; j >= 0; j --){

        printf("%d", allBits[j]);
    }


}