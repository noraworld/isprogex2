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
  q.top->next = NULL;
  q.rear = q.top;

  // q.rear->keyに'b'を代入
  q.rear->next = (struct data *)malloc(sizeof(struct data));
  if (q.rear->next == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  q.rear = q.rear->next;
  q.rear->key = 'b';
  q.rear->next = NULL;

  // q.rear->keyに'c'を代入
  q.rear->next = (struct data *)malloc(sizeof(struct data));
  if (q.rear->next == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  q.rear = q.rear->next;
  q.rear->key = 'c';
  q.rear->next = NULL;


  printf("%c\n", q.top->key);
  printf("%c\n", q.top->next->key);
  printf("%c\n", q.rear->key);

  free(q.top);
  free(q.top->next);
  free(q.top->next->next);

  return 0;
}
