#include<stdio.h>
#include<stdlib.h>
#define ELE (5)
#define NUM (21)

int main() {

  char *name[ELE];
  int i;
  int ele;

  // 各要素ごとに動的メモリを確保する
  for (i = 0; i < ELE; i++)
    name[i] = (char *)malloc(sizeof(char) * NUM);

  // メモリ確保できなかったらエラーを出力
  for (i = 0; i < ELE; i++) {
    if (name[i] == NULL) {
      printf("メモリを確保できません.\n");
      return -1;
    }
  }

  printf("名前を最大%d名分入力してください.\n", ELE);

  for (i = 0; i < ELE; i++) {
    fgets(name[i], NUM-1, stdin);
    if (name[i][0] == '\n') // 空行で入力終了
      break;
  }
  ele = i;

  for (i = 0; i < ele; i++)
    printf("%x %s", name[i], name[i]);

  // 各要素ごとに動的メモリを開放する
  for (i = 0; i < ELE; i++)
    free(name[i]);

  return 0;
}
