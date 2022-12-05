#include <stdio.h>

int main() {
  //define enum
  enum Company {GOOGLE, FACEBOOK, XEROX = 10, YAHOO, EBAY, MICROSOFT};
  
  //assign values
  enum Company company1 = XEROX;
  enum Company company2 = GOOGLE;
  enum Company company3 = EBAY;
  
  //output
  printf("%i\n%i\n%i\n", company1, company2, company3);
  
  return 0;
}
