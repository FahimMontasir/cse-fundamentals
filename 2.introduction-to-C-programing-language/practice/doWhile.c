#include<stdio.h>

int main() {
    int x = 4;

    do {
        scanf("%d", &x);
        printf("x is %d\n", x);
    } while (x<4);
}
