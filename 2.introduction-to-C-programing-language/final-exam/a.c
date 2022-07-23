//Take integer value as input and output that value until you get 42. The integer value will be less than 100
#include<stdio.h>

int main(){
    int num;

    while(1){
        scanf("%d", &num);
        if(num == 42) break;
        printf("%d\n", num);
    }
    return 0;
}



