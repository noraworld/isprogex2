#include<stdio.h>
#define MAX (10)

char pop(char* s, int* top);
void push(char c, char* s, int* top);
void print_stack_ary(char* s, int top);

int main() {

  char s[MAX];
  char c;
  int top = 0;
  char buf_clean;
  char popup;

  while (top < MAX) {
    printf("スタック操作: ");
    scanf("%c", &c);
    scanf("%c", &buf_clean);

    if (c == '0')
      return 0;
    else if (c == '1') {
      popup = pop(s, &top);
      if (popup != '\0') {
	s[top] = '\0';
	printf("pop-upした文字: %c\n", popup);
      }
      print_stack_ary(s, top);
    } else {
      push(c, s, &top);
      print_stack_ary(s, top);
    }

  }

  return 0;
}

char pop(char* s, int* top) {

  if (*top <= 0) {
    printf("スタックが空です\n");
    return '\0';
  }

  *top = *top - 1;
  return s[*top];

}

void push(char c, char* s, int* top) {

  if (*top >= MAX) {
    printf("スタックがいっぱいです\n");
    return;
  }

  s[*top] = c;
  *top = *top + 1;

  return;
}

void print_stack_ary(char* s, int top) {

  printf("<---TOP = %d\n", top);
  while (top > 0) {
    top--;
    printf("%c\n", s[top]);
  }
  putchar('\n');

  return;
}
