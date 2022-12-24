#include<stdio.h>
#include<stdlib.h>

// 構造体定義
struct data {
  char key;
  struct data *next;
};

struct queue {
  struct data *top, *rear;
};

// プロトタイプ宣言
char dequeue(struct queue *q);
void enqueue(struct queue *q, char key);
void print_queue_list(struct queue q);

int main() {

  struct queue q;
  char deq;

  q.top = NULL;
  enqueue(&q, 'a');
  enqueue(&q, 'b');
  enqueue(&q, 'c');

  if (q.top == NULL) {
    printf("キューが空です\n");
    return -1;
  }
  print_queue_list(q);
  while (q.top != NULL) {
    deq = dequeue(&q);
    printf("dequeueした文字: %c\n\n", deq);
    //free(q.top);
    //q.top = q.top->next;
    print_queue_list(q);
  }

  return 0;
}

// デキューする
char dequeue(struct queue *q) {

  char key_temp; // topのkeyを一時保存
  struct data *str_temp;

  key_temp = q->top->key;

  str_temp = q->top;
  q->top = q->top->next;
  free(str_temp);

  return key_temp;
}

// エンキューする
void enqueue(struct queue *q, char key) {

  if (q->top == NULL) {
    q->top = (struct data *)malloc(sizeof(struct data));
    if (q->top == NULL) {
      printf("メモリを確保できません.\n");
      return;
    }
    q->top->key = key;
    q->top->next = NULL;
    q->rear = q->top;
    return;
  }

  q->rear->next = (struct data *)malloc(sizeof(struct data));
  if (q->rear->next == NULL) {
    printf("メモリを確保できません.\n");
    return;
  }
  q->rear = q->rear->next;
  q->rear->key = key;
  q->rear->next = NULL;

  return;
}

// リストをループでたどって画面に出力する
void print_queue_list(struct queue q) {

  int det = 0;

  // リスト内が空のときの例外処理
  if (q.top == NULL) {
    printf("キューが空です.\n\n");
    return;
  }
  // リスト内のデータが1つのときの例外処理
  if (q.top == q.rear) {
    printf("%c<---TOP, REAR\n", q.top->key);
    printf("データが1つしかありません.\n\n");
    return;
  }
  // 通常処理
  while (q.top != q.rear) { // リストの末尾の手前まで出力
    if (det == 0)
      printf("%c<---TOP\n", q.top->key);
    else
      printf("%c\n", q.top->key);
    det++;
    q.top = q.top->next;
  }
  printf("%c<---REAR\n", q.rear->key); // リストの末尾(rear)を出力
  putchar('\n');

  return;
}
