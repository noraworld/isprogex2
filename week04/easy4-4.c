// オプション課題4-4と同じ動作を示すもので一番簡単なアルゴリズム
// オプション課題4-4の意図するプログラムではないと推測する

#include<stdio.h>

int main() {

  int left;
  char operator;
  int right;

  printf("数式を入力してください: ");
  scanf("%d%c%d", &left, &operator, &right);

  if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
    printf("ERROR\n");
    return -1;
  }

  printf("数値1: %d\n", left);
  printf("演算子: %c\n", operator);
  printf("数値2: %d\n", right);

  switch (operator) {
  case '+' : printf("計算結果: %d\n", left + right); break;
  case '-' : printf("計算結果: %d\n", left - right); break;
  case '*' : printf("計算結果: %d\n", left * right); break;
  case '/' : printf("計算結果: %.2f\n", (float)left / (float)right); break;
  }


  return 0;
}
