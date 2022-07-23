#include<stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    for(int I=0; I<t; I++){
        int n;
        scanf("%d", &n);

        int arr[n];
        for(int i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }
        int i=0, j=n-1;
        while(i<j){
            printf("%d ", arr[i]);
            i++;

            printf("%d ", arr[j]);
            j--;
        }
        if(n%2 != 0){
            printf("%d", arr[n/2]);
        }
        t-1 != I && printf("\n");
    }
}
