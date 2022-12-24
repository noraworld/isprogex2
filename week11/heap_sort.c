#include<stdio.h>
#include<stdlib.h>

double deletemin(double a[], int *n);
void insert(double val, double a[], int *n);

void heap_sort(double ary[], int memory) {

  double *a;
  double *result;
  int n = 0;
  int i, j;

  a = (double *)malloc(sizeof(double) * memory);
  if (a == NULL) {
    printf("メモリを確保できません.\n");
    return;
  }

  // insert
  for (i = 0; i < memory; i++)
    insert(ary[i], a, &n);

  // deletemin
  for (i = 0; i < memory; i++)
    ary[i] = deletemin(a, &n);

  free(a);
  return;
}

double deletemin(double a[], int *n) {

  double rootnode, temp;
  int i, j;
  rootnode = a[1];
  a[1] = a[*n];
  a[*n] = '\0';
  (*n)--;

  for (i = 1; (2*i) <= *n; i = j) {

    if (a[2*i+1] == '\0' || a[2*i] <= a[2*i+1]) {
      if (a[i] > a[2*i]) {
	temp = a[i];
	a[i] = a[2*i];
	a[2*i] = temp;
      }
      j = 2*i;
    } else {
      if (a[i] > a[2*i+1]) {
	temp = a[i];
	a[i] = a[2*i+1];
	a[2*i+1] = temp;
      }
      j = 2*i+1;
    }
    
  }

  return rootnode;
}

void insert(double val, double a[], int *n) {

  (*n)++;
  a[*n] = val;

  int i;
  double temp;

  for (i = *n; i > 1; i = i/2) {
    if (a[i] < a[i/2]) {
      temp = a[i];
      a[i] = a[i/2];
      a[i/2] = temp;
    }
  }

  return;
}
