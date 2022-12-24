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
  char key_value, buf_clean;

  top = NULL;
  while (TRUE) {
    printf("keyの値を入力してください: ");
    if (scanf("%c", &key_value) == EOF)  break;
    scanf("%c", &buf_clean);
    push(&top, key_value);
  }

  if (top == NULL) {
    printf("\nスタックが空です\n");
    return -1;
  }

  print_stack_list(top);

  while (top != NULL) {
    popup = pop(&top);
    printf("popした文字: %c\n", popup);
    free(top);
    top = top->next;
    print_stack_list(top);
  }


  return 0;
}

char pop(struct data **top) {

  return (*top)->key;
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

  putchar('\n');
  while (top != NULL) {
    if (det == 0)
      printf("%c<---TOP\n", top->key);
    else
      printf("%c\n", top->key);
    det++;
    top = top->next;
  }
  //printf("入力文字数: %d\n", det);
  putchar('\n');

  return;
}
