#include <stdio.h>

int main() {

  int *ptr;

  int x = 43;
  ptr = &x;

  printf("%d \n", *ptr);

  return 0;
}
