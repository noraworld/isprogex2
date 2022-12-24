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
  int i = 0;
  while (fscanf(fp, "%d", &ary[i]) == 1)
    i++;
  fclose(fp);

  sort(ary, 0, STRMAX-1);

  for (i = 0; i < STRMAX; i++)
    printf("%d ", ary[i]);
  putchar('\n');


  return 0;
}

void sort(int ary[], int left, int right) {

  int mid, i, j, k;
  int temp[STRMAX];

  if (left >= right)
    return;

  mid = (left + right) / 2; // マージした際の添字を保存
  sort(ary, left, mid);     // 左を再帰呼び出し
  sort(ary, mid+1, right);  // 右を再帰呼び出し

  // tempに保存(中央から右までは逆順に代入)
  for (i = 0; i <= mid; i++)
    temp[i] = ary[i];
  for (i = mid+1, j = right; i <= right; i++, j--)
    temp[i] = ary[j];

  i = left;
  j = right;

  // ソートする
  for (k = left; k <= right; k++) {
    if (temp[i] <= temp[j]) {
      ary[k] = temp[i];
      i++;
    }
    else {
      ary[k] = temp[j];
      j--;
    }
  }

  return;
}
