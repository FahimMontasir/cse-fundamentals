//Takahashi and Aoki decided to train themselves by running.
//Takahashi repeats the following schedule: "Run for AAA seconds at BBB meters per second and then rest for CCC seconds."
//Aoki repeats the following schedule: "Run for DDD seconds at EEE meters per second and then rest for FFF seconds."
//When XXX seconds have passed since they simultaneously started running, which of Takahashi and Aoki is ahead?

#include<stdio.h>

int main(){
    int A, B, C, D, E, F, X, tak, aok;
    scanf("%d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &X);

    int x = X/(A+C),y = X%(A+C);
    tak = B*(x*A+y);
    if(y>=A){
        tak = B*(x*A+A);
    }

    int p = X/(D+F), q = X%(D+F);
    aok = E*(p*D+q);
    if(q>=D){
        aok = E*(p*D+D);
    }

    if(tak> aok){
        printf("Takahashi");
    }
    else if(tak<aok){
        printf("Aoki");
    }
    else {
        printf("Draw");
    }
    return 0;
}
