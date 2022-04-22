//problem: There are two types of contest in Artland . Avishek has decided to participate in Artland Beginner Contest (ABC) if his current rating is less than 12001200, and participate in Artland Regular Contest (ARC) otherwise.
//You are given Avishek's current rating, xx. Print ABC if Avishek will participate in ABC, and print ARC otherwise.

#include<stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    x < 1200 ? printf("ABC"): printf("ARC");
    return 0;
}
