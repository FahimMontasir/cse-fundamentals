#include<stdio.h>

int main() {
    int num, abs;
    scanf("%d", &num);
    //condition? true val : false val;

    abs = num >= 0 ? num : -num;
    printf("%d", abs);
}
