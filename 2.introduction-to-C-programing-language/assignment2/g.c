//How many integers not less than AAA and not more than BBB are there?
#include<stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    if(A<B){
        printf("%d",B-A+1);
    }else {
        printf("%d",0);
    }
    return 0;
}
