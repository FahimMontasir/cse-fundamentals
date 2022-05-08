
//    Masud has recently got his dream job at Voogle. To get to his job, he leaves home at SSS o'clock (on the 242424-hour clock) every day and returns home TTT o'clock every day.
//    The date may change while he is out of home. Outside this time period, he always stays at home.
//
//    Determine whether Masud is away from home at 303030 minutes past XXX o'clock.

#include<stdio.h>

int main(){
    int S, T, X, result=0;
    scanf("%d %d %d", &S, &T, &X);

    if(S<T){
        for(int i = S; i<T; i++){
            if(i==X){
                result=1;
                break;
            }
        }
        result?printf("Yes"):printf("No");
    }
    else if(S>T){
        for(int i=S; i<24; i++){
            if(i==X){
                result=1;
                break;
            }
        }
        for(int i=0; i<T; i++){
           if(i==X){
                result=1;
                break;
            }
        }
        result? printf("Yes") : printf("No");
    }
    else if(S==T){
         printf("No");
    }

    return 0;
}
