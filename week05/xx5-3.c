#include<stdio.h>
#include<stdlib.h>

struct data {
  char key;
  struct data *next;
};

struct queue {
  struct data *top, *rear;
};

int main() {

  struct queue q;

  // q.top->keyに'a'を代入
  q.top = NULL;
  q.top = (struct data *)malloc(sizeof(struct data));
  if (q.top == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  q.top->key = 'a';

  // q.top->next->keyに'b'を代入
  q.top->next = NULL;
  q.top->next = (struct data *)malloc(sizeof(struct data));
  if (q.top->next == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  q.top->next->key = 'b';

  // q.top->next->next->keyに'c'を代入
  q.top->next->next = NULL;
  q.top->next->next = (struct data *)malloc(sizeof(struct data));
  if (q.top->next->next == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  q.top->next->next->key = 'c';

  q.top->next->next->next = NULL;

  // q.rearはq.top->next->nextを指す
  q.rear = NULL;
  q.rear = q.top->next->next;

  printf("%c\n", q.top->key);
  printf("%c\n", q.top->next->key);
  printf("%c\n", q.rear->key);

  return 0;
}
