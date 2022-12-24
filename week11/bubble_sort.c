#include<stdio.h>

void bubble_sort(double ary[], int memory) {

  int compare_max;
  int roop_i, roop_j;
  double temp;

  for (compare_max = memory-1; compare_max > 0; compare_max--)
    for (roop_i = 0; roop_i < compare_max; roop_i++)
      if (ary[roop_i] > ary[roop_i+1]) {
	temp = ary[roop_i];
	ary[roop_i] = ary[roop_i+1];
	ary[roop_i+1] = temp;
      }

  return;
}
