//You are given N items. The i’th item has value Ai. You can increase any item’s value by any amount.
//You need to make the value of all the items equal by doing this operation any number of times.
//What is the minimum total amount needed to make all the items equal?

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }

    int max = nums[0];
    for(int i=0; i<n; i++){
        if(nums[i]>max){
            max= nums[i];
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        sum = sum + ((nums[i]- max) * -1);
    }

    printf("%d", sum);

    return 0;
}
