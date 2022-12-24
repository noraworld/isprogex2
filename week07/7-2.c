#include<stdio.h>
#define MAX (16)

void enqueue(char c, char* q, int* top, int* rear);
void print_queue_ary(char* q, int top, int rear);

int main() {

  char q[MAX];
  int top = 0;
  int rear = 0;
  char c;
  char buf_clean;

  while (rear < MAX) {
    printf("キューを入力してください: ");
    if (scanf("%c", &c) == EOF)
      break;
    scanf("%c", &buf_clean);
    enqueue(c, q, &top, &rear);
    print_queue_ary(q, top, rear);
  }

  putchar('\n');
  return 0;
}

void enqueue(char c, char* q, int* top, int* rear) {
  // ※引数のtopは使用していない

  q[*rear] = c;
  (*rear)++;

  return;
}

void print_queue_ary(char* q, int top, int rear) {

  if (top == 0) {
    printf("%c<---TOP = %d\n", q[top], top);
    top++;
  }
  while (top < rear) {
    printf("%c\n", q[top]);
    top++;
  }
  printf("<---REAR = %d\n", rear);

  return;
}
