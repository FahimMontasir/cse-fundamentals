#include<stdio.h>

int main(){
    for(int i =1; i<=10; i++) {
        if(i%3 ==0) continue;

        printf("%d --->", i);
        for(int j=1; j<=10; j++) {
            printf("%d ", i*j);
        }
        printf("\n");
    }
}
