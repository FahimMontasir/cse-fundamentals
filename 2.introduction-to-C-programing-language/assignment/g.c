//Problem: You are given three integers AA, BB and CC. Determine whether CC is not less than AA and not greater than BB.

#include<stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if(C > A && C < B) {
        printf("Yes");
    }
    else if (C == A && C == B) {
        printf("Yes");
    }
    else {
        printf("No");
    }
    return 0;
}
