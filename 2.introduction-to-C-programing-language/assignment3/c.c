//The first line contains integer, the number of beads on the table.
//The next line contains string , which represents the colors of the beads.
//We'll consider the beads in the row numbered from to from left to right. Then the character equals "R",
//if the bead is red, "G", if it's green and "B", if it's blue.

#include<stdio.h>

int main(){
    int n, sum=0;
    scanf("%d", &n);

    char s[n];
    for(int i=0; i<=n; i++){
        scanf("%c", &s[i]);
    }
    for(int i=0; i<=n; i++){
        if(i<n){
            if(s[i]==s[i+1]){
                sum++;
            }
        }
    }
    printf("%d", sum);
    return 0;
}
