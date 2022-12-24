// 数字を降順に並び替える
#include<stdio.h>
#include<stdlib.h>

void sort(double ary[], int memory);

int main() {

  double *ary;
  FILE *fp;
  unsigned i = 0;
  int memory;

  fp = fopen("numbers100K.dat", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }
  fscanf(fp, "%d", &memory);
  ary = (double *)malloc(sizeof(double) * memory);
  if (ary == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  while (fscanf(fp, "%lf", &ary[i]) == 1)
    i++;
  fclose(fp);

  sort(ary, memory);

  fp = fopen("numbers100Kdes.dat", "w");
  for (i = 0; i < memory; i++)
    fprintf(fp, "%f\n", ary[i]);
  fclose(fp);

  return 0;
}


void sort(double ary[], int memory) {

  int compare_max;
  int roop_i, roop_j;
  double temp;

  for (compare_max = memory-1; compare_max > 0; compare_max--)
    for (roop_i = 0; roop_i < compare_max; roop_i++)
      if (ary[roop_i] < ary[roop_i+1]) {
	temp = ary[roop_i];
	ary[roop_i] = ary[roop_i+1];
	ary[roop_i+1] = temp;
      }

  return;
}
