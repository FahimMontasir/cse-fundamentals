//Problem 1: Neil is playing with alphabets. There are 26 alphabets in English Language. 5 of them are vowels: a, e, i, o and u.
//As Neil is a kid, he can't tell it clearly. If he gives you an alphabet c, can you tell him whether it is vowel or consonant.

#include<stdio.h>

int main() {
    char alphabet;
    scanf("%c", &alphabet);

    if(alphabet=='a'||alphabet=='e'||alphabet=='i'||alphabet=='o'||alphabet=='u'){
        printf("vowel");
    }
    else {
        printf("consonant");
    }
    return 0;
}
