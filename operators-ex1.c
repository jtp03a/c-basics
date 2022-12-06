#include <stdio.h>

int main()
{
  int minutes = 0;
  double min_year = 0.0;
  double min_day = 0.0;
  double year = 0.0;
  double day = 0.0;

  printf("Enter a number of minutes: ");
  // get input
  scanf("%d", &minutes);
  
  // calculations
  min_day = 60 * 24;
  min_year = min_day * 365;
  
  day = minutes / min_day;
  year = minutes / min_year;

  printf("%d minutes is \n%f of a year and \n%f of a day\n", minutes, year, day);

  return 0;
}