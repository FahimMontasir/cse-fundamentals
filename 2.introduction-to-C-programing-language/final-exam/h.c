#include<stdio.h>

int main(){
    int i, j;
    char str[101];
    scanf("%s", str);

    int len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i] == '+')
        {
            for(j=i; j<len; j++)
            {
                str[j] = str[j+1];
            }
            len--;
            i--;
        }
    }


    printf("%s", str);
}
