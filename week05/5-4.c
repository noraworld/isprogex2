#include<stdio.h>
#include<stdlib.h>

struct data {
  char key;
  struct data *next;
};

struct queue {
  struct data *top, *rear;
};

void print_queue_list(struct queue q);

// キーボードから入力を受け付け、リストへの挿入を行う
int main() {

  struct queue q;
  char key_value, buf_clean;
  int det = 1;

  q.top = NULL;
  // 1回目の入力
  printf("keyの値を入力してください: ");
  if (scanf("%c", &key_value) == EOF)
    det = 0;
  while (det == 1) {
    scanf("%c", &buf_clean);
    q.top = (struct data *)malloc(sizeof(struct data));
    if (q.top == NULL) {
      printf("メモリを確保できません.\n");
      return -1;
    }
    q.top->key = key_value;
    q.top->next = NULL;
    q.rear = q.top;
    det++;
  }

  // 2回目以降の入力
  while (det == 2) {
    printf("keyの値を入力してください: ");
    if (scanf("%c", &key_value) == EOF)  break;
    scanf("%c", &buf_clean);
    // リストへの挿入
    q.rear->next = (struct data *)malloc(sizeof(struct data));
    if (q.rear->next == NULL) {
      printf("メモリを確保できません.\n");
      return -1;
    }
    q.rear = q.rear->next;
    q.rear->key = key_value;
    q.rear->next = NULL;
  }

  // 画面に出力する関数を呼び出す
  print_queue_list(q);

  // メモリを開放する
  while (q.top != NULL) {
    free(q.top);
    q.top = q.top->next;
  }

  return 0;
}

// リストをループでたどって画面に出力する
void print_queue_list(struct queue q) {

  int det = 0;

  putchar('\n');

  // リスト内が空のときの例外処理
  if (q.top == NULL) {
    printf("キューが空です.\n");
    return;
  }
  // リスト内のデータが1つのときの例外処理
  if (q.top == q.rear) {
    printf("%c<---TOP, REAR\n", q.top->key);
    printf("データが1つしかありません.\n");
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
  return;
}
