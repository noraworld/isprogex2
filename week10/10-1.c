#include<stdio.h>

int main() {

  int ary[] = {1, 13, 14, 60, 15, 71, 24, 91, 80, 63};
  unsigned i;

  for (i = 0; i < (sizeof(ary) / sizeof(int)); i++)
    printf("%d ", ary[i]);
  putchar('\n');

  return 0;
}
