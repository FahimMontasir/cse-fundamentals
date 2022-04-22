//You will be given three numbers X, Y and N. You need to print the integers from 11 to NN.
//If any number is divisible by XX then replace it with Fizz or, if they are divisible by YY, replace it with Buzz.
// If the number is divisible by both XX and YY, you print FizzBuzz instead.

#include<stdio.h>

int main() {
    int X, Y, N;
    scanf("%d %d %d", &X, &Y, &N);

    for(int i= 1; i<=N; i++){
        if(i%X==0 && i%Y==0){
            printf("FizzBuzz\n");
        }
        else if(i%X == 0){
            printf("Fizz\n");
        }
        else if(i%Y == 0) {
            printf("Buzz\n");
        }
        else {
            printf("%d\n",i);
        }
    }
    return 0;
}
