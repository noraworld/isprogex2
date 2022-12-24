#include<stdio.h>
#define SORT_NUM (10)

int deletemin(int a[], int *n);
void insert(int val, int a[], int *n);
int check_heap(int a[], int n);

int main() {

  int a[SORT_NUM+1] = {0};
  int n = 0;
  int val;
  int check_heap_val = 2;
  int i, j;

  // ファイルから読み込んで数字をinsertする
  FILE *fp;
  fp = fopen("numbers.dat", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません\n");
    return -1;
  }
  while (fscanf(fp, "%d", &val) == 1)
    insert(val, a, &n);
  fclose(fp);

  // insert直後のHEAP
  printf("delete前のHEAP = [ ");
  for (i = 1; i <= n; i++)
    printf("%d ", a[i]);
  printf("]\n");

  int result[SORT_NUM];
  // deletemin
  for (i = 0; i < SORT_NUM; i++) {
    result[i] = deletemin(a, &n);
    printf("DELETED = %d\n", result[i]);
    printf("%d回delete後のHEAP = [ ", i+1);
    for (j = 1; j <= n; j++)
      printf("%d ", a[j]);
    printf("]\n");
  }

  /*
  // check_heap
  check_heap_val = check_heap(a, n);
  printf("check_heap_val = %d\n", check_heap_val);
  if (check_heap_val == 0)
    printf("ヒープが成立していません\n");
  if (check_heap_val == 1)
    printf("ヒープが成立しています\n");
  */

  // 昇順に並べた結果
  printf("\n昇順に並べた結果\n");
  for (i = 0; i < 10; i++)
    printf("%d ", result[i]);
  putchar('\n');


  return 0;
}

int deletemin(int a[], int *n) {

  int rootnode, temp, i, j; // jは次に比べる対象の添字
  rootnode = a[1];
  a[1] = a[*n];
  a[*n] = '\0';
  (*n)--;

  for (i = 1; (2*i) <= *n; i = j) {

    if (a[2*i+1] == '\0' || a[2*i] <= a[2*i+1]) {
      if (a[i] > a[2*i]) {    // ヒープが崩れていたら
	temp = a[i];
	a[i] = a[2*i];
	a[2*i] = temp;
      }
      j = 2*i;
    } else {
      if (a[i] > a[2*i+1]) {  // ヒープが崩れていたら
	temp = a[i];
	a[i] = a[2*i+1];
	a[2*i+1] = temp;
      }
      j = 2*i+1;
    }
    
  }


  /*
  for (i = 1; (2*i) <= *n; i = j) {

    if ((2*i+1) <= *n) {        // 右子が存在する場合
      if (a[2*i] <= a[2*i+1]) { // 左子が小さいなら
	if (a[i] > a[2*i]) {    // ヒープが崩れていたら
	  temp = a[i];
	  a[i] = a[2*i];
	  a[2*i] = temp;
	  j = 2*i;
	}
      } else {                  // 右子が小さいなら
	if (a[i] > a[2*i+1]) {  // ヒープが崩れていたら
	  temp = a[i];
	  a[i] = a[2*i+1];
	  a[2*i+1] = temp;
	  j = 2*i+1;
	}
      }
    }

    if ((2*i+1) > *n) {        // 右子が存在しない場合
      if (a[i] > a[2*i]) {     // 左子と比較してヒープが崩れていたら
	temp = a[i];
	a[i] = a[2*i];
	a[2*i] = temp;
	j = 2*i;
      }
    }


  }
  */


  return rootnode;
}

void insert(int val, int a[], int *n) {

  // 一番最後の添字に値をinsertする
  (*n)++;
  a[*n] = val;

  int i; // 新しくinsertした値を指す添字
  int temp;
  // ヒープを成立させる
  for (i = *n; i > 1; i = i/2) {
    if (a[i] < a[i/2]) {
      temp = a[i];
      a[i] = a[i/2];
      a[i/2] = temp;
    }
  }

  return;
}

int check_heap(int a[], int n) {

  unsigned i;

  for (i = 1; (2*i) <= n; i++) { // 左子が存在すれば実行
    if (a[i] > a[2*i]) // 左子の判定
      return 0;
    if (2*i+1 <= n) { // 右子が存在すれば実行
      if (a[i] > a[2*i+1]) // 右子の判定
	return 0;
    }
  }

  return 1;
}
