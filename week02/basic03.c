#include<stdio.h>

int main() {

  char *p1, *p2;
  p2 = "Winter";
  p1 = p2;

  while (*p1 != '\0') {
    p1++;
  }

  while (p1 != p2) {
    p1--;
    putchar(*p1);
  }
  putchar('\n');

  return 0;
}
