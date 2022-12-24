#include<stdio.h>
#define STRMAX (10)

void sort(int ary[], int left, int right);

int main() {

  int ary[STRMAX];

  // ファイルから読み取り値を代入
  FILE *fp;
  fp = fopen("numbers.dat", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません\n");
    return -1;
  }
  int roop_i = 0;
  while (fscanf(fp, "%d", &ary[roop_i]) == 1)
    roop_i++;
  fclose(fp);

  sort(ary, 0, STRMAX-1);

  for (roop_i = 0; roop_i < STRMAX; roop_i++)
    printf("%d ", ary[roop_i]);
  putchar('\n');


  return 0;
}

void sort(int ary[], int left, int right) {

  int mid, i, j, k;
  int temp[STRMAX];

  if (left >= right)
    return;

  mid = (left + right) / 2;
  sort(ary, left, mid);
  sort(ary, mid+1, right);

  for (i = mid+1, j = right; i <= right; i++, j++)
    temp[i] = ary[i];

  i = left;
  j = right;

  for (k = left; k <= right; k++) {
    if (temp[i] <= temp[j])
      ary[k] = temp[i++];
    else
      ary[k] = temp[j--];
  }


  return;
}
