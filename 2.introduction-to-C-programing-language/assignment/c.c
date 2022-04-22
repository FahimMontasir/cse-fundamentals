//Ireland’s winters can be very bad. The temperatures sometimes dip to uncomfortable levels. Weather Service wants to find out exactly how bad the winter was.
//More specifically, they are interested in knowing the total number of daysin which the temperature was below zero degree Celsius.

#include<stdio.h>

int main() {
    int n, sum=0, temp;
    scanf("%d", &n);

    for(int i= 1; i<=n; i++){
        scanf("%d", &temp);
        if(temp < 0){
           sum+=1;
        }
    }
    printf("%d", sum);
    return 0;
}
