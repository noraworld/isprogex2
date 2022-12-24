#include<stdio.h>
#define MAX (32)

char dequeue(char* q, int* top, int* rear);
void enqueue(char c, char* q, int* top, int* rear);
void print_queue_ary(char* q, int top, int rear);

int main() {

  char q[MAX];
  int top = 0;
  int rear = 0;
  char c;
  char deq;
  char buf_clean;

  while (rear < MAX) {
    printf("キューを入力してください: ");
    scanf("%c", &c);
    scanf("%c", &buf_clean);

    if (c == '0')
      return 0;
    else if (c == '1') {
      deq = dequeue(q, &top, &rear);
      if (deq != '\0')
	printf("dequeueした文字: %c\n", deq);
      print_queue_ary(q, top, rear);
    } else {
      enqueue(c, q, &top, &rear);
      print_queue_ary(q, top, rear);
    }

  }


  return 0;
}

char dequeue(char* q, int* top, int* rear) {

  if ( (*top) >= (*rear) ) {
    printf("dequeueする値が見つかりません.\n");
    return '\0';
  }

  char temp; // topの値を一時保存
  temp = q[(*top)];
  q[(*top)] = '\0';
  (*top)++;

  return temp;
}

void enqueue(char c, char* q, int* top, int* rear) {
  // ※引数のtopは使用していない

  q[*rear] = c;
  (*rear)++;

  return;
}

void print_queue_ary(char* q, int top, int rear) {

  printf("%c<---TOP = %d\n", q[top], top);
  top++;
  while (top < rear) {
    printf("%c\n", q[top]);
    top++;
  }
  printf("<---REAR = %d\n\n", rear);

  return;
}
