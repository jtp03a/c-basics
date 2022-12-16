#include <stdio.h>

//constants
#define BASEPAY 12.00
#define OVERTIME_RATE 1.5
#define FULLTIME_HOURS 40
#define TAXBRACKET_300 300
#define TAXRATE_300 .15
#define TAXBRACKET_450 450
#define TAXRATE_450 .20
#define TAXRATE .25

int main() {

  //variables
  int hours = 0;
  float pay = 0.0;
  float taxes = 0.0;
  float netPay = 0.0;

  // user input
  printf("How many hours did you work this week: ");
  scanf("%i", &hours);

  // calculate pay based on overtime or not
  if (hours > FULLTIME_HOURS) {
    pay = (40 * BASEPAY) + ((hours - 40) * (BASEPAY * OVERTIME_RATE));
  } else {
    pay = hours * BASEPAY;
  }

  // calcuate taxes based on total pay
  if (pay > TAXBRACKET_450) {
    taxes = (TAXBRACKET_300 * TAXRATE_300) + ((TAXBRACKET_450 - TAXBRACKET_300) * TAXRATE_450) + ((pay - TAXBRACKET_450) * TAXRATE);
  } else if (TAXBRACKET_300 < pay <= TAXBRACKET_450) {
    taxes = (TAXBRACKET_300 * TAXRATE_300) + ((pay - TAXBRACKET_300) * TAXRATE_450);
  } else {
    taxes  = pay * TAXRATE_300;
  }

  // calculate net pay
  netPay = pay - taxes;

  // output results
  printf("Gross Pay: %.2f\n", pay);
  printf("Taxes: %.2f\n", taxes);
  printf("Net Pay: %.2f", netPay);

  return 0;
}