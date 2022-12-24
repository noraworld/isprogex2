#include<stdio.h>

void quick_sort(double ary[], int left, int right) {

  int i, j;
  double temp;

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

  quick_sort(ary, left, i-1);   // ピボットより左を再帰呼び出し
  quick_sort(ary, i+1, right);  // ピボットより右を再帰呼び出し

  return;
}
