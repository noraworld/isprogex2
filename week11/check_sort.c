#include<stdio.h>
#include<stdlib.h>
#define MAX (1000000050)

int main() {

  char filename[32];
  FILE *fp;
  double *ary;

  printf("ファイル名: ");
  scanf("%s", filename);
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }

  ary = (double *)malloc(sizeof(double) * MAX);
  if (ary == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }

  // 一番上の行にデータ数があるファイルのときに使用(不使用時はコメントアウト)
  int dmy;
  fscanf(fp, "%d", &dmy);

  unsigned i = 0;
  while (fscanf(fp, "%lf", &ary[i]) == 1) {
    i++;
    if (i >= MAX-1) {
      printf("データ数が多すぎます.\n");
      free(ary);
      return -1;
    }
  }
  fclose(fp);

  unsigned j = 0;
  while (j < i-1) {
    if (ary[j] > ary[j+1]) {
      printf("昇順に並んでいません.\n");
      free(ary);
      return -1;
    }
    j++;
  }

  printf("昇順に並んでいます.\n");
  free(ary);
  return 0;
}
