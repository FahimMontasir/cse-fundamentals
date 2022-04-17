#include<stdio.h>
#include<stdbool.h>

int main() {
    int num;
    scanf("%d", &num);

    bool is_leap_year = (num%4 == 0) && (num%100 != 0 || num%400 ==0);

    if(num >= 0 && num <= 10) { // we have also || (or) ! (not)
        printf("okey");
    } else {
        printf("not okey");
    }
}
