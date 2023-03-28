#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Refer to README.md for the problem instructions

char *checkAmount(double amount)
{
   int intPart = (int)amount;
   float decPart = amount - intPart;
   decPart = decPart * 100;
   int intDecPart = (int)decPart;
   char decStr[12];
   sprintf(decStr, "%d", intDecPart);

   char *ones[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
   char *tens[] = {"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
   char *tensMult[] = {"", "", "TWENTY", "THIRTY", "FOURTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};

   char *checkValueInWords = (char*)malloc(100 * sizeof(char));

   if (intPart < 10) {
      strcat(checkValueInWords, ones[intPart]);
   } else if (intPart > 9 && intPart < 20) {
      intPart = intPart - 10;
      strcat(checkValueInWords, tens[intPart]);
   } else {
      int onesDigit = intPart % 10;
      int tensDigit = (intPart - onesDigit) / 10;
      strcat(checkValueInWords, tensMult[tensDigit]);
      strcat(checkValueInWords, " ");
      strcat(checkValueInWords, ones[onesDigit]);
   }

   strcat(checkValueInWords, " AND ");
   strcat(checkValueInWords, decStr);
   strcat(checkValueInWords, "/100");

   return checkValueInWords;
}

int main(){
   checkAmount(55.59);
}
