#include<stdio.h>
#define MAX (10)

void sort(int ary[]);

int main() {

  FILE *fp;
  int ary[MAX];

  fp = fopen("numbers.dat", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません\n");
    return -1;
  }

  unsigned i = 0;
  while (fscanf(fp, "%d", &ary[i]) == 1)
    i++;

  fclose(fp);

  sort(ary); // 要素を昇順にソートする

  for (i = 0; i < MAX; i++)
    printf("%d ", ary[i]);
  putchar('\n');

  return 0;
}

void sort(int ary[]) {

  unsigned i;
  unsigned compare_first; // 比較対象の最初の要素
  unsigned min_element; // 最小の値が格納されている配列の添字
  int min; // 配列内の最小の値
  int temp; // 入れ替えを行うための一時変数

  for (compare_first = 0; compare_first < MAX-1; compare_first++) {
    min = ary[compare_first]+1;
    for (i = compare_first; i < MAX; i++) {
      if (min > ary[i]) {
	min = ary[i];
	min_element = i;
      }
    }
    temp = ary[compare_first];
    ary[compare_first] = ary[min_element];
    ary[min_element] = temp;
  }

  return;
}
