//Hasan knew that you are a programmer. He is now going to test your math knowledge. He will give you N numbers of calculations.
//In each calculation you will be given two numbers A and B. You need to calculate the multiplication of these two numbers.
// And after all the calculations you have to tell the total sum of those calculated multiplications. Can you do it?

#include<stdio.h>

int main() {
    int N;
    float sum=0, A, B;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%f %f", &A, &B);
        sum = sum+(A*B);
    }
    printf("%.3f", sum);
    return 0;
}
