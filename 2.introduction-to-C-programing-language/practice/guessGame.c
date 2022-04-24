#include<stdio.h>
#include<stdlib.h>

int main() {
    srand(time(0));
    int hidden = rand()%100 + 1;

    int number_of_guess = 0;
    while(number_of_guess < 10) {
        int guess;
        scanf("%d", &guess);

        if(guess == hidden) {
            printf("you are right\n");
            break;
        }
        else if(guess > hidden){
            printf("guess smaller\n");
        }
        else {
            printf("guess larger\n");
        }

        number_of_guess++;
    }
    if(number_of_guess == 10) {
        printf("You failed");
    }
}
