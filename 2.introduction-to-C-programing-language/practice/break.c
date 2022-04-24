#include<stdio.h>
#include<stdbool.h>

int main(){
    while(true) {
        int input ;
        scanf("%d", &input);
        printf("%d\n", input);

        if(input == 0) {
            break;
        }
    }
}
