#include<stdio.h>

int main(){
    int N, K, x=1;
    scanf("%d", &N);
    scanf("%d", &K);

    for(int i=0; i<N; i++){
        if(2*x<x+K){
            x= 2*x;
        }
        else{
            x= x+K;
        }
    }
    printf("%d",x);
    return 0;
}
