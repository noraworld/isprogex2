// 問題文から、読み取りは1行で行うものと推測する。本プログラムはfgetsを使用。

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define ELE (64)

int main() {

  char numerical[ELE];
  char left[ELE];
  char operator;
  char right[ELE];
  int num_left;
  int num_right;
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int m = 0;
  int ope_counter = 0;

  printf("数式を入力してください: ");
  fgets(numerical, sizeof(numerical)-1, stdin);

  while (numerical[l] != '\n')
    l++;
  numerical[l] = '\0';

  // 四則演算子の個数をカウントする
  while (numerical[i]) {
    if (numerical[i] == '+' || numerical[i] == '-' || numerical[i] == '*' || numerical[i] == '/')
      ope_counter++;
    i++;
  }

  // 四則演算子がない、または2個以上あれば不正な入力とみなす
  if (ope_counter != 1) {
    printf("ERROR: no operator or too many operator\n");
    return -1;
  }

  // 1文字目(0番目の要素)が四則演算子なら不正な入力とみなす
  if (numerical[0] == '+' || numerical[0] == '-' || numerical[0] == '*' || numerical[0] == '/') {
    printf("ERROR: location of operator is wrong (element 1)\n");
    return -1;
  }

  // iをナル文字のある要素まで進める
  i = 0;
  while (numerical[i] != '\0')
    i++;
  i--;

  // 一番最後の文字(ナル文字の手前)が四則演算子なら不正な入力とみなす
  if (numerical[i] == '+' || numerical[i] == '-' || numerical[i] == '*' || numerical[i] == '/') {
    printf("ERROR: location of operator is wrong (element terminal)\n");
    return -1;
  }

  /* ここまでで、四則演算子の位置は正しい状態となっている */

  // 四則演算子の前までiを進める
  i = 0;
  while (numerical[i] != '+' && numerical[i] != '-' && numerical[i] != '*' && numerical[i] != '/')
    i++;

  // 四則演算子の左辺(数字かどうかは不明)を配列leftに格納
  for (j = 0; j < i; j++)
    left[j] = numerical[j];
  left[i] = '\0';

  // 左辺に英字や記号が含まれていたら不正な入力とみなす
  j = 0;
  while (left[j]) {
    if (isdigit(left[j]) == 0) {
      printf("ERROR: left side is not number\n");
      return -1;
    }
    j++;
  }

  // jをナル文字のある要素まで進める
  j = 0;
  while (numerical[j] != '\0')
    j++;

  // 四則演算子の右辺(数字かどうかは不明)を配列rightに格納
  for (k = i+1, m = 0; k < j; k++, m++)
    right[m] = numerical[k];
  right[m] = '\0';

  // 右辺に英字や記号が含まれていたら不正な入力とみなす
  k = 0;
  while (right[k]) {
    if (isdigit(right[k]) == 0) {
      printf("ERROR: right side is not number\n");
      return -1;
    }
    k++;
  }

  // 四則演算子を格納
  operator = numerical[i];

  printf("数値1: %s\n", left);
  printf("演算子: %c\n", operator);
  printf("数値2: %s\n", right);

  // atoi()で文字としての数字を、数値としての数字に変換してint型変数に格納
  num_left = atoi(left);
  num_right = atoi(right);

  // 四則演算結果を出力
  switch (operator) {
  case '+' : printf("計算結果: %d\n", num_left + num_right); break;
  case '-' : printf("計算結果: %d\n", num_left - num_right); break;
  case '*' : printf("計算結果: %d\n", num_left * num_right); break;
  case '/' : printf("計算結果: %.2f\n", (float)num_left / (float)num_right); break;
  }



  return 0;
}

/* 本プログラムのアルゴリズムについて
1. 演算子がただ1つだけ存在するかを確認する
2. 演算子の位置が一番左もしくは一番右に存在していないかを確認する

手順1, 2で演算子の位置は正しくなるので
演算子を境にして左と右に分ける

3. 左に数字以外のものが含まれていないか確認する
4. 右に数字以外のものが含まれていないか確認する
5. 左, 右の数字をatoi()で数値に変換してint型変数に格納する
6. 演算子の種類をswitch文で分け, それぞれに合った計算処理を行う
7. 数値と演算子および実行結果を出力する
*/
