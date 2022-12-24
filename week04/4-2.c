#include<stdio.h>

void swap(int *x, int *y);

int main() {

  int x;
  int y;

  printf("2つの整数値を入力してください: ");
  scanf("%d%d", &x, &y);


  printf("変数xの値は%d, 変数yの値は%dです.\n", x, y);
  swap(&x, &y); // swap()を呼び出してxとyの値を入れ替える
  printf("swap()を呼び出した後の変数xの値は%d, 変数yの値は%dです.\n", x, y);


  return 0;
}


void swap(int *x, int *y) {

  int temp = *x;
  *x = *y;
  *y = temp;

}
