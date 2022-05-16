#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d", &n);

    while(n--){
        char strs[101];
        scanf("%s", strs);

        int len = strlen(strs);
        printf("%c", strs[0]);

        for(int i=1; i< len-1; i+=2){
            printf("%c", strs[i]);
        }
       printf("%c\n", strs[len-1]);
    }

    return 0;
}
