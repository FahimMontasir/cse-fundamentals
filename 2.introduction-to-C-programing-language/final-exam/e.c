#include<stdio.h>

int main(){
    int t, n, i, j, position, swap, minV;
    scanf("%d", &t);

    for(int I=0; I<t; I++){
        scanf("%d", &n);
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

        minV = (a[0]- a[1])* -1;
        for(i = 0; i < n-1; i++){
            int tempMin = (a[i]- a[i+1])* -1;
            if(minV>tempMin){
                minV = tempMin;
            }
        }
        printf("%d", minV);
        t-1 != I && printf("\n");
    }
    return 0;
}
