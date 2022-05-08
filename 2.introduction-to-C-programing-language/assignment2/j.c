#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int abc;
    scanf("%d", &abc);

    int c = abc%10;
    int ab = abc/10;
    int b = ab%10;
    int a = ab/10;

    char s1[20];
    char s2[20];
    char s3[20];

    // Convert both the integers to string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);
    sprintf(s3, "%d", c);

char str[80];
strcpy(str, s2);
strcat(str, s3);
strcat(str, s1);

int p = atoi(str);

char stre[80];
strcpy(stre, s3);
strcat(stre, s1);
strcat(stre, s2);

int q = atoi(stre);

printf("%d", abc+p+q);
}
