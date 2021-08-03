#include <stdio.h>
#include <stdlib.h>
#include "safe_mem.h"

int main() {
  char *ptr = smalloc(sizeof(char));
  int *arr = smalloc(5 * sizeof(int));
  // *ptr = 'a';
  // printf("%c\n", *ptr);
  sfree(ptr);
  sfree(ptr);
  
  sfree(arr);

  int a = 5;
  int *b = &a;
  sfree(b);
}
