#include<stdio.h>
#include<stdlib.h>

// data型の構造体
struct data {
  char key;
  struct data *next;
};

int main() {

  // top->keyに'a'を代入
  struct data *top = NULL;
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

  printf("%c\n", top->key);
  printf("%c\n", top->next->key);
  printf("%c\n", top->next->next->key);

  free(top);
  free(top->next);
  free(top->next->next);

  return 0;
}
