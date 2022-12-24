#include<stdio.h>

void select_sort(double ary[], int memory) {

  unsigned i;
  unsigned compare_first;
  unsigned min_element;
  double min;
  double temp;

  for (compare_first = 0; compare_first < memory-1; compare_first++) {
    min = ary[compare_first]+1;
    for (i = compare_first; i < memory; i++) {
      if (min > ary[i]) {
	min = ary[i];
	min_element = i;
      }
    }
    temp = ary[compare_first];
    ary[compare_first] = ary[min_element];
    ary[min_element] = temp;
  }

  return;
}
