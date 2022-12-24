#include<stdio.h>
#define MAX (256)
#define TRUE (1)

int deletemin(int a[], int *n);
void insert(int val, int a[], int *n);
int check_heap(int a[], int n);

int main() {

  int a[MAX];
  int n = 0;
  int val;
  int check_heap_val = 2;
  int min;

  while (TRUE) {
    printf("insertする値: ");
    if (scanf("%d", &val) == EOF)
      break;
    insert(val, a, &n);
  }
  putchar('\n');

  min = deletemin(a, &n);
  printf("deleteminした値: %d\n", min);

  int i;
  for (i = 0; i <= n; i++)
    printf("%d ", a[i]);
  putchar('\n');

  check_heap_val = check_heap(a, n);

  if (check_heap_val == 0)
    printf("ヒープが成立していません\n");
  if (check_heap_val == 1)
    printf("ヒープが成立しています\n");

  return 0;
}

int deletemin(int a[], int *n) {

  int min_temp;
  (*n)--;
  min_temp = a[0];
  a[0] = a[*n];
  a[*n] = '\0';
  (*n)--;

  // 再構成
  unsigned i;
  int exchange_temp;
  for (i = 0; (2*i + 1) < *n; i++) {
    if (a[2*i + 1] <= a[2*i + 2]) { // 左子が小さい
      if (a[i] > a[2*i + 1]) {
	exchange_temp = a[i];
	a[i] = a[2*i + 1];
	a[2*i + 1] = exchange_temp;
      }
    }
    else // 右子が小さい
      if (a[i] > a[2*i + 2]) {
	exchange_temp = a[i];
	a[i] = a[2*i + 2];
	a[2*i + 2] = exchange_temp;
      }
  }

  return min_temp;
}

void insert(int val, int a[], int *n) {

  a[*n] = val;
  (*n)++;

  return;
}

int check_heap(int a[], int n) {

  unsigned i;

  for (i = 0; (2*i + 1) < n; i++) { // 左子が存在すれば実行
    if (a[i] > a[2*i + 1]) // 左子の判定
      return 0;
    if (2*i + 2 < n) { // 右子が存在すれば実行
      if (a[i] > a[2*i + 2]) // 右子の判定
	return 0;
    }
  }

  return 1;
}
