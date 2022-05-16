#include<stdio.h>

int main(){
    int a, d;
    scanf("%d %d", &a, &d);

    int arr[a];
    for(int i=0; i<a; i++){
        scanf("%d", &arr[i]);
    }
        for(int i=d; i<a; i++){
            printf("%d ", arr[i]);
        }
        for(int i=0; i<d; i++){
            printf("%d ", arr[i]);
        }
}
