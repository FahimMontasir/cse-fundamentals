#include<stdio.h>

int main() {
    int n, A=0, D=0;
    scanf("%d", &n);

    for(int i=0; i<=n; i++){
        char won;
        scanf("%c", &won);
        if(won == 'A'){
             A++;
        }
        else if(won == 'D'){
            D++;
        }
    }
    if(A>D){
        printf("Anton");
    }
    else if(A<D){
        printf("Danik");
    }
    else{
        printf("Friendship");
    }
    return 0;
}
