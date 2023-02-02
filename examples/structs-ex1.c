#include <stdio.h>

int main() {
  
  struct Employee {
    char name[20];
    int hireDate;
    float salary;
  };
  
  struct Employee emp1 = {"Jake Peterson", 10, 100000.02};
  
  printf("%s, %i, %.2f\n", emp1.name, emp1.hireDate, emp1.salary);
  
  struct Employee emp2;
  
  printf("What is the employees name:? ");
  scanf("%s", &emp2.name);
  printf("What is the number of the day of the month the employee started? ");
  scanf("%i", &emp2.hireDate);
  printf("What is the employees salary? ");
  scanf("%f", &emp2.salary);
  
  printf("%s, %i, %.2f\n", emp2.name, emp2.hireDate, emp2.salary);
  
  return 0;
}

