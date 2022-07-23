#include<stdio.h>

void change_array(int arr[], int n){
    for(int i = 0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}
int main(){
    int arr[6] = {9, 8, 7, 2, 4, 3};
    change_array(arr, 6);
    for(int i = 0; i < 6; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
