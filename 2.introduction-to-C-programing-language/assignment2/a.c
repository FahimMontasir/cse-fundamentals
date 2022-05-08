//There are NNN people numbered 1,2,…,N1, 2, \ldots, N1,2,…,N. We have KKK gifts.
//Staring with Person AAA , gifts are distributed one by one sequentially. In other words,
//people receive gifts in the following order: A,A+1,A+2,…,N,1,2,…A, A+1, A+2, \ldots, N, 1, 2, \ldotsA,A+1,A+2,…,N,1,2,….
//Who will receive the last gift?

#include<stdio.h>

int main(){
    int N, K, A, count;
    scanf("%d %d %d", &N, &K, &A);

    for(int i=0; i<K; i++){
        if(i == 0){
            count = A;
        }
        else if(count == N) {
            count = 1;
        }
        else {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
