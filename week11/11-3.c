#include<stdio.h>
#define STRMAX (10)

void sort(int ary[], int left, int right);
void print_midterm(int ary[], int pibot, int left, int right);

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

  printf("整列前\n");
  for (i = 0; i < STRMAX; i++)
    printf("%d ", ary[i]);
  printf("\n\n整列中\n");

  sort(ary, 0, STRMAX-1);

  printf("\n整列後\n");
  for (i = 0; i < STRMAX; i++)
    printf("%d ", ary[i]);
  printf("\n");


  return 0;
}

void sort(int ary[], int left, int right) {

  int i, j, temp;

  if (left >= right)
    return;

  i = left;
  j = right-1;

  // ソート対象内の一番右の要素をピボットに選ぶ
  while (i <= j) {
    if (ary[i] <= ary[right])
      i++;
    if (ary[j] >= ary[right])
      j--;
    if (i <= j && ary[i] > ary[right] && ary[j] < ary[right]) {
      temp = ary[i];
      ary[i] = ary[j];
      ary[j] = temp;
      i++;
      j--;
    }
  }
  // ピボット(対象内の一番右) と ピボットが入る場所 を入れ替え
  temp = ary[i];
  ary[i] = ary[right];
  ary[right] = temp;

  print_midterm(ary, i, left, right);  // 途中経過を表示

  sort(ary, left, i-1);   // ピボットより左を再帰呼び出し
  sort(ary, i+1, right);  // ピボットより右を再帰呼び出し

  return;
}

void print_midterm(int ary[], int pibot, int left, int right) {

  int k;

  for (k = 0; k < STRMAX; k++) {
    // 比較対象の一番左にパーレン
    if (k == left)
      printf("(");
    // 要素を表示(ブラケットがピボットを表す)
    if (k == pibot)
      printf(" [%d] ", ary[k]);
    else
      printf(" %d ", ary[k]);
    // 比較対象の一番右にパーレン閉じ
    if (k == right)
      printf(")");
  }

  printf("\n");

  return;
}
