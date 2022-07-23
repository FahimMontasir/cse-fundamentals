#include<stdio.h>

int main(){
    int n, sum=0;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    //calculating sum of the array
    for(int i=0; i<n; i++){
        sum = sum+ arr[i];
    }
    printf("%d", sum);
    return 0;
}
