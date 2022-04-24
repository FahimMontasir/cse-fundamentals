#include<stdio.h>

int main() {
    int a, b, gcd =1;
    scanf("%d %d", &a, &b);

    while (a != 0){
        int rem = b%a;
        b =a ;
        a = rem;
        printf("%d %d\n", a, b);
    }
    printf("gcd = %d\n", b);
//    for(int g=1; g<=a && g<=b; g++){
//        if (a%g == 0 && b%g == 0){
//            gcd = g;
//        }
//    }
//    printf("%d\n", gcd);
}

/*
a  b   rem
30 42  12
12 30  6
6 12   0
0 6
*/
