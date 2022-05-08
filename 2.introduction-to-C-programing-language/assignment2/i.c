//Samantha takes an coding exam. She will 100100100 and get a grade according to the marks she gets in the exam, as follows:
//    Newbie, if her marks are not less than 000 but less than 404040;
//    Pupil, if her marks are not less than 404040 but less than 707070;
//    Specialist, if her marks are not less than 707070 but less than 909090;
//    Expert, if her marks are not less than 909090.
//Samantha took this test and got XXX points.
//Find the minimum number of extra points needed to go up one grade higher. If, however, her grade was Expert, print expert as there is no higher grade than that.
#include<stdio.h>

int main(){
    int X;
    scanf("%d", &X);

    if(X>=0 && X<40){
        printf("%d", 40-X);
    }
    else if(X>=40 && X<70){
        printf("%d", 70-X);
    }
    else if(X>=70 && X<90){
        printf("%d", 90-X);
    }
    else {
        printf("expert");
    }
    return 0;
}
