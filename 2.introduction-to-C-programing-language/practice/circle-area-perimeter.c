/*

Write a program to find the perimeter and area of a circle.
the program will ask the user for a radius. Then print the perimeter and area.

sample interaction:
  enter radius: 1
  perimeter: 6.28
  area = 3.14
Formula:
  perimeter = 2 * pi * r
  area = pi * r ^ 2
*/
#include<stdio.h>

int main() {
  printf("Enter radius: ");

  double radius;
  scanf("%lf", &radius);

  const double PI = 3.1416;

  double perimeter = 2 * PI * radius;
  printf("perimeter = %.2lf\n", perimeter); //%.2 means 0.00

  double area = PI * radius * radius;
  printf("area = %.2lf", area);

  return 0;
}
