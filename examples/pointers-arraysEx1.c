#include <stdio.h>
#include <string.h>

int main(void) {
  char multiple[] = "a string";
  char *p = multiple;
  
  for (int i = 0; i < strnlen(multiple, sizeof(multiple)); i++) {
    printf("multiple[%d] = %c *(p+%d) = %c &multple[%d] = %p p+%d = %p\n", i, multiple[i], i, *(p+i), i, &multiple[i], i, p+i);
  }
  
  long multiple[] = {15L, 25L, 35L, 45L};
  long * p2 = multiple;
  
  for (int i = 0; i < sizeof(multiple)/sizeof(multiple[0]); i++) {
    printf("address p+%d (&multiple[%d]): %llu    *(p+%d)   value: %d\n", i, i, (unsigned long long)(p2+i), i, *(p2+i));
    
    printf("\n    Type long occupie: %d bytes\n", (int)sizeof(long));
  }
  
  return 0;
}
