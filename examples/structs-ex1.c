#include <stdio.h>

struct Employee {
  char name[20];
  int hireDate;
  float salary;
};

int main() {
  

  
  struct Employee emp1 = {"Jake Peterson", 10, 100000.02};
  
  printf("%s, %i, %.2f\n", emp1.name, emp1.hireDate, emp1.salary);
  
  printf("What is the employees name:? ");
  scanf("%s", &emp1.name);
  printf("What is the number of the day of the month the employee started? ");
  scanf("%i", &emp1.hireDate);
  printf("What is the employees salary? ");
  scanf("%f", &emp1.salary);
  
  printf("%s, %i, %.2f\n", emp1.name, emp1.hireDate, emp1.salary);
  
  return 0;
}

