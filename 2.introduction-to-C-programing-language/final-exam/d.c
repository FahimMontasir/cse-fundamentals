#include<stdio.h>

int main(){
    int n, m, i, j, position, swap, sum=0;
    scanf("%d %d", &n, &m);
    int a[n];

    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n - 1; i++){
        position=i;
        for(j = i + 1; j < n; j++){
            if(a[position] > a[j])
            position=j;
        }
        if(position != i){
            swap=a[i];
            a[i]=a[position];
            a[position]=swap;
        }
    }

    for(i = 0; i < m; i++){
        if(a[i]<0){
            sum+=a[i];
        }
    }
    printf("%d", sum*-1);
    return 0;
}
