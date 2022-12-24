#include<stdio.h>
#include<stdlib.h> // malloc()を使用
#include<ctype.h> // atoi(), toupper() を使用
#define STRLEN (16)
#define SUCCESS (0)
#define FAILED (-1)

int main() {

  char strlen[STRLEN]; // 文字列最大長を文字として格納する
  int num; // 文字列最大長を数値として格納する
  char *str; // mallocでメモリを確保するchar型へのポインタ
  unsigned i;
  char *p; // 文字列を逆順に並べる際に用いるchar型へのポインタ

  printf("文字列最大長を入力してください: ");
  fgets(strlen, sizeof(strlen)-1, stdin);

  i = 0;
  while (strlen[i] != '\n')
    i++;
  strlen[i] = '\0';

  i = 0;
  while (strlen[i] != '\0') {
    if (isdigit(strlen[i]) == 0) {
      printf("不正なデータ入力です.\n");
      return FAILED;
    }
    i++;
  }

  num = atoi(strlen);
  num += 2; // ナル文字と改行コード(fgetsの仕様)分だけ要素数を増やす

  // mallocで動的メモリを確保する
  str = (char *)malloc(sizeof(char) * num);
  if (str == NULL) {
    printf("メモリを確保できません.\n");
    return FAILED;
  }

  printf("文字列を入れてください: ");
  fgets(str, num, stdin); // 要素数はsizeof(str)ではなくnum
  i = 0;
  while (str[i] != '\n')
    i++;
  str[i] = '\0';

  // 大文字に変換
  i = 0;
  while (str[i]) {
    str[i] = toupper(str[i]);
    i++;
  }

  p = str;
  while (*p != '\0')
    p++;
  while (p != str) {
    p--;
    putchar(*p);
  }
  putchar('\n');

  free(str); // 確保したメモリを開放する

  return SUCCESS;
}
