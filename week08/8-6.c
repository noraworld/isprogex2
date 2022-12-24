#include<stdio.h>
#include<stdlib.h> // malloc
#define TRUE (1)

struct data {
  char key;
  struct data *next;
};

char pop(struct data **top);
void push(struct data **top, char key);
void print_stack_list(struct data *top);

int main() {

  struct data *top;
  char popup;

  char c;
  char buf_clean;

  top = NULL;
  while (TRUE) {
    printf("スタック操作: ");
    scanf("%c", &c);
    scanf("%c", &buf_clean);

    if (c == '0')
      return 0;
    else if (c == '1') {
      popup = pop(&top);
      if (popup != '\0')
	printf("popした文字: %c\n", popup);
      print_stack_list(top);
    } else {
      push(&top, c);
      print_stack_list(top);
    }

  }

  /*
  if (top == NULL) {
    printf("スタックが空です\n");
    return -1;
  }
  print_stack_list(top);
  while (top != NULL) {
    popup = pop(&top);
    printf("popした文字: %c\n\n", popup);
    print_stack_list(top);
  }
  */

  return 0;
}

char pop(struct data **top) {

  char key_temp; // topのkeyを一時保存
  struct data *str_temp; // topを一時保存

  if ( (*top) == NULL) {
    printf("スタックが空です.\n");
    return '\0';
  }

  key_temp = (*top)->key;

  str_temp = *top;
  *top = (*top)->next;
  free(str_temp);

  return key_temp;
}

void push(struct data **top, char key) {

  struct data *p;
  // リストへの挿入
  p = (struct data *)malloc(sizeof(struct data));
  if (p == NULL) {
    printf("メモリを確保できません.\n");
    return;
  }
  p->key = key;
  p->next = *top;
  *top = p;

  return;
}

// リストをループでたどって画面に出力する
void print_stack_list(struct data *top) {

  int det = 0;

  /*
  if (top == NULL) {
    printf("スタックが空です\n");
    return;
  }
  */

  while (top != NULL) {
    if (det == 0)
      printf("%c<---TOP\n", top->key);
    else
      printf("%c\n", top->key);
    det++;
    top = top->next;
  }
  putchar('\n');

  return;
}
