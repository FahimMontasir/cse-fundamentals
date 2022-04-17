#include<stdio.h>

int main() {
    int num1, num2, result;
    char op;

    scanf("%d %c %d", &num1, &op, &num2);

    switch (op) {
        case '+':
            printf("%d", num1+num2);
            break;
        case '-':
           printf("%d", num1-num2);
           break;
        default:
            printf("unknown operator");
    }
}
