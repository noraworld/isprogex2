#include<stdio.h>
#define MAX (32)

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

  char str_s[MAX];
  int str_top = 0;
  char popup = '\0';
  int flag = 0;

  // 仮のスタックにコピー(同じ文字があったら削除する)
  while (*top > 0) {
    if (s[(*top)-1] == c) {
      popup = pop(s, top);
      printf("%c が2回入力されたので削除しました\n", popup);
      flag = 1;
    }
    if (flag == 1)
      break;
    str_s[str_top] = pop(s, top);
    str_top++;
  }

  // コピーしたスタックを元のスタックに戻す
  while (str_top > 0) {
    s[*top] = pop(str_s, &str_top);
    (*top)++;
  }

  // 削除していなければ新たな文字をプッシュ
  if (popup == '\0') {
    s[*top] = c;
    *top = *top + 1;
  }

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
