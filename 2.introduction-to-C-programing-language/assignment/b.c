//problem: Goam, a magician gives you a magic number, and you must count up to that number,
//starting at 11, saying “Abracadabra” each time. You will understand more if you look at the sample input output.

#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        printf("%d Abracadabra\n", i);
    }
    return 0;
}
