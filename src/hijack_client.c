#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = malloc(sizeof(char));
  int *arr = malloc(5 * sizeof(int));
  // *ptr = 'a';
  // printf("%c\n", *ptr);
  free(ptr);
  free(ptr);

  free(arr);

  int a = 5;
  int *b = &a;
  free(b);
}
