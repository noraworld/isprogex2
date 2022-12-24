#include<stdio.h>
#include<stdlib.h>
#define TRUE (1)

struct data {
  char key;
  struct data *next;
};

void print_stack_list(struct data *top);

// キーボードから入力を受け付け、リストへの挿入を行う
int main() {

  struct data *top, *p;
  char key_value, buf_clean;

  top = NULL;
  while (TRUE) {
    // キーボードからの入力受付
    printf("keyの値を入力してください: ");
    if (scanf("%c", &key_value) == EOF)  break;
    scanf("%c", &buf_clean);  // バッファのクリーニング
    // リストへの挿入
    p = (struct data *)malloc(sizeof(struct data));
    if (p == NULL) {
      printf("メモリを確保できません.\n");
      return -1;
    }
    p->key = key_value;
    p->next = top;
    top = p;
  }

  // 画面に出力する関数を呼び出す
  print_stack_list(top);

  // メモリの開放
  while (top != NULL) {
    free(top);
    top = top->next;
  }

  return 0;
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

  return;
}
