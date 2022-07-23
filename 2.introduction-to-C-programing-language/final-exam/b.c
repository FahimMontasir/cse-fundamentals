/*Ashiq doesn't love strings. But he really likes letter 'a'. He assumes a string beautiful if more than half of it's character are 'a'. For example some beautiful strings are "baaba", "a", "aqawa" , but "abb", "waeaia" are not.
As Ashiq only loves beautiful strings, so he wanted to erase some character (possibly zero) from the string s such that the string become longest beautiful string. So he wants to know what will be the size of longest string remaining after erase some character( possibly zero) to get a beautiful string.
It is guaranteed that the string will consist of atleast one 'a'. So answer always exists. */

#include<stdio.h>
#include<string.h>

int main(){
    char s[51];
    scanf("%s", s);

    int countA = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]=='a'){
            countA++;
        }
    }
    if(countA<strlen(s)-countA || countA<= strlen(s)/2 ){
        if(strlen(s)< 2*countA-1){
            printf("%d",strlen(s));
        } else{
            printf("%d", 2*countA -1);
        }
    }else {
        printf("%d",strlen(s));
    }

}
