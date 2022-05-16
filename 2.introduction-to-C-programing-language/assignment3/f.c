#include<stdio.h>

int main(){
    long long num;
    scanf("%I64d",&num);

    int numarr[100]={0}, count=0, sum=0;
    while(num > 0) //do till num greater than  0
    {
        int mod = num % 10;  //split last digit from number
        numarr[count] = mod;
        num = num / 10;    //divide num by 10. num /= 10 also a valid one
        count++;
    }

    for(int i=0; i<count; i++){
        if(numarr[i] == 4 || numarr[i] == 7){
            sum++;
        }
    }

    if(sum== 4 || sum == 7){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
