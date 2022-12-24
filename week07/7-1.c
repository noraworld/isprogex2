#include<stdio.h>
#define MAX (16)

void print_queue_ary(char* q, int top, int rear);

int main() {

  char q[MAX];
  int top = 0;
  int rear = 0;

  q[rear] = 'a';  rear++;
  q[rear] = 'b';  rear++;
  q[rear] = 'c';  rear++;
  q[rear] = 'd';  rear++;

  print_queue_ary(q, top, rear);

  return 0;
}

void print_queue_ary(char* q, int top, int rear) {

  printf("%c<---TOP = %d\n", q[top], top);
  q[top] = '\0';
  top++;
  while (top < rear) {
    printf("%c\n", q[top]);
    q[top] = '\0';
    top++;
  }
  printf("<---REAR = %d\n", rear);

  return;
}
