#include<stdio.h>
#include<stdlib.h>

// data型の構造体
struct data {
  char key;
  struct data *next;
};

void print_stack_list(struct data *top);

int main() {

  struct data *top;
  struct data *p;

  // top->keyに'a'を代入
  top = NULL;
  top = (struct data *)malloc(sizeof(struct data));
  if (top == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  top->key = 'a';
  top->next = NULL;

  // top->next->keyに'b'を代入
  top->next = (struct data *)malloc(sizeof(struct data));
  if (top->next == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  top->next->key = 'b';
  top->next->next = NULL;

  // top->next->next->keyに'c'を代入
  top->next->next = (struct data *)malloc(sizeof(struct data));
  if (top->next->next == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  top->next->next->key = 'c';
  top->next->next->next = NULL;

  top->next->next->next = (struct data *)malloc(sizeof(struct data));
  if (top->next->next->next == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  top->next->next->next->key = 'd';
  top->next->next->next->next = NULL;

  print_stack_list(top);

  /*
  printf("%c\n", top->key);
  printf("%c\n", top->next->key);
  printf("%c\n", top->next->next->key);
  */

  return 0;
}


void print_stack_list(struct data *top) {

  struct data *cur; // 一時変数

  cur = top; // 一時変数に先頭(top)を代入

  printf("%c<---TOP\n", cur->key); // 先頭要素を出力
  cur = cur->next; // 一時変数を、一時変数自体のnextで更新

  while (cur != NULL) { // nextがNULLになったら終了
    printf("%c\n", cur->key); // リストの各要素(key)を出力
    cur = cur->next; // 一時変数を、一時変数自体のnextで更新
  }

  return;
}
