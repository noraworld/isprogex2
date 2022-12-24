#include<stdio.h>

int main() {

  int x;
  double y = 0;

  printf("value = ");
  scanf("%d", &x);

  unsigned i;
  for (i = 1; i <= x; i++)
    y += 1;

  printf("x = %d\n", x);
  printf("y = %.0f\n", y);

  return 0;
}
