// 課題の仕様は、mallocで構造体メモリを確保するのではなく
// ループ内で一回ずつメモリを確保して格納するプログラムである

#include<stdio.h>
#include<stdlib.h>
#define ELE (64)

typedef struct {
  char code[ELE];
  char name[ELE];
  int price;
} gift;

int main() {

  FILE *sfp;
  FILE *dfp;
  gift *gifts;
  char fname[ELE];
  int data;
  int i;

  printf("データ数を入力してください: ");
  scanf("%d", &data);

  gifts = (gift *)malloc(sizeof(gift) * data);

  if (gifts == NULL) {
    printf("メモリを確保できませんでした.\n");
    return -1;
  }

  printf("ファイル名を指定してください: ");
  scanf("%s", fname);
  sfp = fopen(fname, "r");
  if (sfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }

  for (i = 0; i < data; i++)
    fscanf(sfp, "%s%s%d", gifts[i].code, gifts[i].name, &gifts[i].price);

  fclose(sfp);

  dfp = fopen("gifts2.dat", "w");
  if (sfp == NULL) {
    printf("エラーが発生しました.\n");
    return -1;
  }

  for (i = 0; i < data; i++) {
    fprintf(dfp, "code: %s\n", gifts[i].code);
    fprintf(dfp, "name: %s\n", gifts[i].name);
    fprintf(dfp, "price: %d\n", gifts[i].price);
    if (i < data-1)
      fprintf(dfp, "\n");
  }

  fclose(dfp);
  free(gifts);

  printf("表示形式変換後ファイルに出力しました.\n");

  return 0;
}
