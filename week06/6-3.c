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
    printf("スタックを入力してください: ");
    if (scanf("%c", &c) == EOF)
      break;
    scanf("%c", &buf_clean);
    push(c, s, &top);
  }

  print_stack_ary(s, top);
  while (top > 0) {
    popup = pop(s, &top);
    s[top] = '\0';
    printf("pop-upした文字: %c\n", popup);
    print_stack_ary(s, top);
  }

  return 0;
}

char pop(char* s, int* top) {

  *top = *top - 1;
  return s[*top];

}

void push(char c, char* s, int* top) {

  s[*top] = c;
  *top = *top + 1;

  return;
}

void print_stack_ary(char* s, int top) {

  printf("\n<---TOP = %d\n", top);
  while (top > 0) {
    top--;
    printf("%c\n", s[top]);
  }

  return;
}
