#include<stdio.h>

int main(){
    int x;
    scanf("%d", &x);

    int sum= 0, reversed=0;
    while(x>0){
        int digit = x%10;
        x/=10;
        sum +=digit;
        reversed = reversed * 10 + digit;
    }
    printf("digit sum = %d and reversed = %d", sum, reversed);
}
