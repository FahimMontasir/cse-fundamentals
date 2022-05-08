//Ragnar Lothbrok is a restless warrior and family man who longs to find and explore new countries across the sea , his most important wish is to find lands which are Good for planting . That's why he asked you to help him to express his feelings about lands.
//
//Ragnar likes the Inception so much, and like that his feelings are complicated. They have n layers. The first layer is hate, second one is love, third one is hate and so on...
//
//For example if n = 1, then his feeling is "I hate it" or if n = 2 it's "I hate that I love it", and if n = 3 it's "I hate that I love that I hate it" and so on.
#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        if(i%2 != 0){
            printf("I hate");
        }
        else if(n==i){
            printf(" that I love");
        }
        else{
            printf(" that I love that ");
        }

        if(i == n){
            printf(" it");
        }
    }


    return 0;
}
