#include<stdio.h>
#define MAX (10)

void sort(int ary[]);

int main() {

  // numbers.datから読み込んで配列に代入
  FILE *fp;
  fp = fopen("numbers.dat", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません\n");
    return -1;
  }
  int ary[MAX];
  int roop_i = 0;
  while (fscanf(fp, "%d", &ary[roop_i]) == 1)
    roop_i++;
  fclose(fp);

  sort(ary); // 要素を昇順にバブルソート

  // ソート完了後の配列を表示
  printf("\nソート完了後の配列\n");
  for (roop_i = 0; roop_i < MAX; roop_i++)
    printf("%d ", ary[roop_i]);
  putchar('\n');


  return 0;
}


void sort(int ary[]) {

  int compare_max;
  int roop_i, roop_j;
  int temp;

  for (compare_max = MAX-1; compare_max > 0; compare_max--) {
    for (roop_i = 0; roop_i < compare_max; roop_i++) {
      
      // 途中経過を表示
      for (roop_j = 0; roop_j < MAX; roop_j++)
	printf("%d ", ary[roop_j]);
      putchar('\n');
      
      if (ary[roop_i] > ary[roop_i+1]) {
	temp = ary[roop_i];
	ary[roop_i] = ary[roop_i+1];
	ary[roop_i+1] = temp;
      }
    }
    putchar('\n');
  }

  return;
}
