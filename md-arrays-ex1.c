// Uses a 2 dimensional array to find the total rainfall for each year, average yearly rainfall, and average rainfall for each month
// Create a 2D array with 5 rows and 12 columns, rows are years, columns are months
// Array should be float

#include <stdio.h>

int main() {
  float rainData[5][12] = {
    {0.22, 0.44, 1.84, 1.06, 0.36, 0.21, 0.00, 0.00, 1.65, 0.99, 5.57, 1.15},
    {3.31, 0.03, 1.52, 0.88, 0.45, 0.01, 0.19, 0.00, 0.00, 1.21, 0.00, 11.25},
    {0.17, 0.24, 4.69, 5.71, 0.15, 0.01, 0.00, 0.00, 0.00, 0.00, 1.15, 1.95},
    {8.63, 12.02, 9.13, 0.41, 3.16, 0.20, 0.00, 0.00, 0.22, 0.00, 3.70, 6.38},
    {3.38, 0.57, 6.26, 0.02, 0.83, 0.00, 0.01, 0.00, 0.00, 0.98, 3.21, 2.54}
  };

  char *months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

  float avgOfTrackedYears;
  float avgOfTrackedMonths[12] = {0};
  int currentYear = 2018;

  for (int i = 0; i < 5; i++) {
    float totalYearlyRainfall = 0;
    for (int j = 0; j < 12; j++) {
      totalYearlyRainfall += rainData[i][j];
      avgOfTrackedMonths[j] += rainData[i][j];
    }
    printf("%d: %f\n", currentYear, totalYearlyRainfall);
    avgOfTrackedYears += totalYearlyRainfall;
    currentYear++;
  }

  printf("Average over 5 Years: %f\n", avgOfTrackedYears / 5);
  for (int i = 0; i < 12; i++) {
    printf("%s: %.2f ", months[i], avgOfTrackedMonths[i] / 5);
  }

  return 0;
}
