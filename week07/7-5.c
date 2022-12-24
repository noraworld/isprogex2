#include<stdio.h>
#define MAX (64)

char dequeue(char* q, int* top, int* rear);
void enqueue(char c, char* q, int* top, int* rear);
void print_queue_ary(char* q, int top, int rear);

int main() {

  char q[MAX] = {'\0'};
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

  char temp;
  temp = q[(*top)];
  q[(*top)] = '\0';
  (*top)++;

  return temp;
}

void enqueue(char c, char* q, int* top, int* rear) {

  char str_q[MAX];
  int str_top = 0;
  int str_rear = 0;
  int temp_top;
  char deq = '\0';
  int flag = 0;

  // 仮のキューにコピー(同じ文字があったら削除する)
  temp_top = *top;
  while (temp_top < *rear) {
    flag = 0;
    if (q[temp_top] == c) {
      deq = dequeue(q, &temp_top, rear);
      printf("%c が2回入力されたので削除しました\n", deq);
      (*top)++;
      flag = 1;
    }
    if (flag != 1) {
      str_q[str_rear] = dequeue(q, &temp_top, rear);
      str_rear++;
    }
  }

  // コピーしたキューを元のキューに戻す
  temp_top = *top;
  while (temp_top < *rear) {
    q[temp_top] = dequeue(str_q, &str_top, &str_rear);
    temp_top++;
  }

  // 削除していなければ新たな文字をエンキュー
  if (deq == '\0') {
    q[*rear] = c;
    (*rear)++;
  }

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
