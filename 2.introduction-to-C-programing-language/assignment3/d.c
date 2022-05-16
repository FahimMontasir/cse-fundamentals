//Output the same word after capitalizing the first character

#include<stdio.h>
#include<ctype.h>

int main(){
    char word[1001];
    scanf("%s", word);
    //change the first char of the word
    word[0]= toupper(word[0]);

    printf("%s", word);
    return 0;
}
