#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
  //declare variables
  double width, height, perimeter, area;
  
  //assign variables
  width = atoi(argv[1]); //atoi converts the string to int
  height = atoi(argv[2]);
  perimeter = 0;
  area = 0;
  
  //calculations
  perimeter = (width + height) * 2;
  area = width * height;
  
  //output
  printf("The perimeter of your rectangle with height, %.2f, and width, %.2f is: %.2lf\n", height, width, perimeter);
  printf("The area of your rectangle with height, %.2f, and width, %.2f is: %.2lf\n", height, width, area);
  
  return 0;
}
