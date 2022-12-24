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
  unsigned compare_max; // 比較対象の最後の要素(比較回数)
  unsigned insert; // 該当する各要素を後ろへ挿入
  int temp; // 挿入を行うための一時変数
  int flag; // ループを抜けるためのフラグ

  for (compare_max = 1; compare_max < MAX; compare_max++) {
    flag = 0;
    for (i = 0; i < compare_max; i++) {
      temp = ary[compare_max];
      if (ary[compare_max] < ary[i]) {
	insert = compare_max;
	while (insert > i) {
	  ary[insert] = ary[insert-1];
	  insert--;
	}
	ary[i] = temp;
	flag++;
      }
      if (flag == 1)  break;
    }
  }

  return;
}
