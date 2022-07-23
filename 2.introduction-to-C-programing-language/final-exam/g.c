#include<stdio.h>

int main(){
    int L, R, len;
    scanf("%d %d", &L, &R);
    char S[100001];
    scanf("%s", S);
    L= L-1;
    R= R-1;
    int res = R-L;
    if(res%2==0){
        len = R/2;
    }else{
        len = R/2+1;
    }

    for(int i=L, j=R; i<=len; i++, j--){
       char temp = S[i];
       S[i] = S[j];
       S[j] = temp;
    }
    printf("%s",S);
}
