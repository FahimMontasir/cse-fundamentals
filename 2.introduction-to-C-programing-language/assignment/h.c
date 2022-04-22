//problem: Subbir has two integers AA and BB . Output the value of A + BA+B.
//However, if A + BA+B is 1010 or greater, output error instead.

#include<stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    A+B >= 10? printf("error"): printf("%d", A+B);
    return 0;
}
