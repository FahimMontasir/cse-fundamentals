#include<stdio.h>

int main() {
  int english_num;
  int accounting_num;

  printf("Enter English and Acc: ");
  scanf("%d %d", &english_num, &accounting_num);

  int total = english_num + accounting_num;

  printf("Total num: %d", total);

}
