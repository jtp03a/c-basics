#include <stdio.h>

int gcd(int a, int b);
float abs_value(float num);
float square_root(float num);
double power(double num, int exponent);

// finds the greatest common divisor of two non-negative integer values, takes two ints
int gcd(int a, int b) {
  // Euclid's algorithm
  if (a == 0) {
    // Then the GCD is b
    return b;
  }
  if (b == 0) {
    // Then the GDC is a
    return a;
  }
  if (a == b ) {
    return a;
  }
  // quotient remainder form - a = b * q + r
  int higher_num = a > b ? a : b; 
  int lower_num = a < b ? a : b;
  int remainder = higher_num % lower_num;

  while (remainder > 0) {
    higher_num = lower_num;
    lower_num = remainder;
    remainder = higher_num % lower_num;
  }

  higher_num = lower_num;

  return higher_num;
}

// finds the absolute value of a number - takes a float and return a float
float abs_value(float num) {
  if (num >= 0)
    return num;
  else
    return -num;
}

// compute the square root of a number, if negative is passed then display a message and -1.0 should be returned
double power(double num, int exponent) {
  double result = num;
  for (int i = 1; i < exponent; i++) {
    result *= num;
  }
  return result;
}

float square_root(float num) {
  if (num < 0) {
    printf("A negative number was received");
    return -1.0;
  }
  int integer_part = 0;
  for (float sqrt = 1; sqrt * sqrt <= num; sqrt++ ) {
    integer_part = sqrt;
  }
  if (integer_part * integer_part == num) {
    return integer_part;
  }
  int precision = 6;
  double dec_part = 0;
  double result = 0;
  for (double dec_place = 1; dec_place <= precision; dec_place++) {
    for (dec_part = 1/(power(10, dec_place)); (integer_part + dec_part) * (integer_part + dec_part) <= num; dec_part += 1/(power(10, dec_place))) {
      result = integer_part + dec_part;
      printf("%f\n", result);
    }
  }
  return result;
}

int main() {
  
  printf("%d\n", gcd(9, 3));
  printf("%.2f\n", abs_value(-50));
  printf("%f\n", square_root(5));

  return 0;
}