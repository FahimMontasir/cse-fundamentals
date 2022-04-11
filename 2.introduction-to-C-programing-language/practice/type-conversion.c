#include<stdio.h>

int main(){
  double realnumber = 10.5;
  int number = realnumber; //implicit conversion

  printf("number = %d, realnumber = %lf\n", number, realnumber);

  double fr_number = 20.5;
  printf("int_num = %d", (int)fr_number); //explicit type conversion
}
