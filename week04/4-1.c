// プログラム付近のコメントは正しく動作するプログラムにするための注釈

#include<stdio.h>

void swap(int x, int y); // ポインタの指す値(*x, *y)を受け取る

int main() {

  int x, y;
  x = 2;
  y = 5;

  swap(x, y); // アドレス(&x, &y)を渡す

  printf("x = %d, y = %d\n", x, y);

  return 0;
}


void swap(int x, int y) {

  // x, y → *x, *y
  int temp = x;
  x = y;
  y = temp;
}

/*
【実行結果】
x = 2, y = 5
*/
