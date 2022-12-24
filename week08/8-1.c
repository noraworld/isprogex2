#include<stdio.h>
#include<stdlib.h> // malloc

struct data {
  char key;
  struct data *next;
};

void push(struct data **top, char key);
void print_stack_list(struct data *top);

int main() {

  struct data *top;

  top = NULL;
  // push関数->print関数でpushを1回ずつ確認する
  push(&top, 'a');
  print_stack_list(top);
  push(&top, 'b');
  print_stack_list(top);
  push(&top, 'c');
  print_stack_list(top);

  // メモリの開放
  while (top != NULL) {
    free(top);
    top = top->next;
  }

  return 0;
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
