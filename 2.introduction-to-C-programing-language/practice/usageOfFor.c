#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;  // \t for tab and align

    for(int i=1; i <=n; i++){
        sum+=i;
    }
    printf("Sum = %d", sum);
}
