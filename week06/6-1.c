#include<stdio.h>
#define MAX (10)

void print_stack_ary(char* s, int top);

int main() {

  char s[MAX];
  int top = 0;

  s[top] = 'a';  top++;
  s[top] = 'b';  top++;
  s[top] = 'c';  top++;
  s[top] = 'd';  top++;

  print_stack_ary(s, top);

  return 0;
}

void print_stack_ary(char* s, int top) {

  printf("<---TOP = %d\n", top);
  while (top > 0) {
    top--;
    printf("%c\n", s[top]);
  }

  return;
}
