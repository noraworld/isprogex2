#include<stdio.h>

void insert_sort(double ary[], int memory) {

  unsigned i;
  unsigned compare_max;
  unsigned insert;
  double temp;
  int flag;

  for (compare_max = 1; compare_max < memory; compare_max++) {
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
