#include<stdio.h>
#include<stdlib.h>

void marge_sort(double ary[], int left, int right) {

  int mid, i, j, k;

  if (left >= right)
    return;

  mid = (left + right) / 2;
  marge_sort(ary, left, mid);
  marge_sort(ary, mid+1, right);

  double temp[right+1];
  for (i = 0; i <= mid; i++)
    temp[i] = ary[i];
  for (i = mid+1, j = right; i <= right; i++, j--)
    temp[i] = ary[j];

  i = left;
  j = right;

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
