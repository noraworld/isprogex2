#include<stdio.h>

int check_heap(int a[], int n);

int main() {

  int a[] = {1, 13, 14, 60, 15, 71, 24, 91, 80, 63};
  int n = sizeof(a) / sizeof(int);
  int check_heap_val = 2;
  int i;

  for (i = 0; i < (sizeof(a) / sizeof(int)); i++)
    printf("%d ", a[i]);
  putchar('\n');

  check_heap_val = check_heap(a, n);

  printf("check_heap_val = %d\n", check_heap_val);

  if (check_heap_val == 0)
    printf("ヒープが成立していません\n");

  if (check_heap_val == 1)
    printf("ヒープが成立しています\n");

  return 0;
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
