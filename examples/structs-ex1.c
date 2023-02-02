#include <stdio.h>

int main() {
  
  struct Employee {
    char name[20];
    int hireDate;
    float salary;
  };
  
  struct Employee emp1 = {"Jake Peterson", 10, 100000.01};
  
  printf("%s, %i, %.2f", emp1.name, emp1.hireDate, emp1.salary);
  
  return 0;
}

