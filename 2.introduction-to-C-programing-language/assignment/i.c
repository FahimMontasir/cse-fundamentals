//Problem: In the vacation of Ramadan,Alex decided to arrange an Ifter party. He has to buy two watermelons for making juice
//The store sells three kinds of watermelons for the price of aa, bb and cc taka , respectively.
//Find the minimum total price of two different watermelons.

#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a+b < a+c && a+b < b+c){
        printf("%d", a+b);
    }
    else if (a+c < a+b && a+c < b+c){
       printf("%d", a+c);
    }
    else {
        printf("%d", b+c);
    }
    return 0;
}
