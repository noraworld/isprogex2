#include<stdio.h>
#define MAX (256)
#define TRUE (1)

void insert(int val, int a[], int *n);
int check_heap(int a[], int n);

int main() {

  int a[MAX+1] = {0};
  int n = 0;
  int val;
  int check_heap_val = 2;
  int i;

  while (TRUE) {
    printf("insertする値: ");
    if (scanf("%d", &val) == EOF)
      break;
    insert(val, a, &n);
  }
  putchar('\n');

  check_heap_val = check_heap(a, n);

  printf("HEAP = [ ");
  for (i = 1; i <= n; i++)
    printf("%d ", a[i]);
  printf("]\n");

  printf("check_heap_val = %d\n", check_heap_val);
  if (check_heap_val == 0)
    printf("ヒープが成立していません\n");
  if (check_heap_val == 1)
    printf("ヒープが成立しています\n");

  return 0;
}

void insert(int val, int a[], int *n) {

  // 一番最後の添字に値をinsertする
  (*n)++;
  a[*n] = val;

  int i; // 新しくinsertした値を指す添字
  int temp;
  // ヒープを成立させる
  for (i = *n; i > 1; i = i/2) {
    if (a[i] < a[i/2]) {
      temp = a[i];
      a[i] = a[i/2];
      a[i/2] = temp;
    }
  }

  return;
}

int check_heap(int a[], int n) {

  unsigned i;

  for (i = 1; (2*i) <= n; i++) { // 左子が存在すれば実行
    if (a[i] > a[2*i]) // 左子の判定
      return 0;
    if (2*i+1 <= n) { // 右子が存在すれば実行
      if (a[i] > a[2*i+1]) // 右子の判定
	return 0;
    }
  }

  return 1;
}
