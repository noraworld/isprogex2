#include<stdio.h>

int main() {

  double val = 5.100000;
  int i;

  // 5.000000だと5回実行
  // 5.100000だと6回実行

  for (i = 0; i < val; i++)
    printf("hello world.\n");

  return 0;
}
