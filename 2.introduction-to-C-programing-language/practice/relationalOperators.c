#include<stdio.h>
#include<stdbool.h>

int main() {
    int a = 5;
    int b = 4;
    bool condition = false;
    int condition2 = a >= b;

    if(condition2) {
        printf("true");
    } else {
        printf("false");
    }
}
