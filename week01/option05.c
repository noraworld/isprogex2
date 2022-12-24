#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SUCCESS (0)
#define FAILED (-1)
#define ELEMENT (64)
#define BUF_ELEMENT (256)

int main() {

  FILE *sfp;
  FILE *dfp;
  char buf[BUF_ELEMENT];
  char code[ELEMENT];
  char name[ELEMENT];
  int price;
  int ch;
  unsigned i;

  // ファイルをオープンする
  sfp = fopen("gifts.dat", "r");
  if (sfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FAILED;
  }

  dfp = fopen("gifts2.dat", "w");
  if (dfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FAILED;
  }

  // fgets + sscanf で1行ずつデータを読み取る（isprogex1/week14/basic04.c参照）
  while (fgets(buf, sizeof(buf)-1, sfp) != NULL) {

    // 1行に3つのデータがある場合（priceが空白ではない場合）
    if (sscanf(buf, "%s%s%d", code, name, &price) == 3) {
      /* 大文字に変換 */
      i = 0;
      while (code[i]) {
	code[i] = toupper(code[i]);
	i++;
      }
      i = 0;
      while (name[i]) {
	name[i] = toupper(name[i]);
	i++;
      }
      /* ---------- */
      fprintf(dfp, "%s %-17s %6d\n", code, name, price);
    }

    // 1行に2つしかデータがない場合（priceが空白の場合）
    else if (sscanf(buf, "%s%s", code, name) == 2) {
      /* 大文字に変換 */
      i = 0;
      while (code[i]) {
	code[i] = toupper(code[i]);
	i++;
      }
      i = 0;
      while (name[i]) {
	name[i] = toupper(name[i]);
	i++;
      }
      /* ---------- */
      fprintf(dfp, "%s %-17s   xxxx\n", code, name);
    }

  } // while(fgets...の閉じカッコ

  // ファイルをクローズする
  fclose(sfp);
  fclose(dfp);

  // ファイルをオープンする（gifts2.datをwriteモードではなくreadモードでオープンする）
  dfp = fopen("gifts2.dat", "r");
  if (dfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FAILED;
  }

  // データを出力する
  while ((ch = fgetc(dfp)) != EOF)
    putchar(ch);

  // ファイルをクローズする
  fclose(dfp);

  // 確認
  char command[ELEMENT];
  putchar('\n');
  do {
    printf("gifts.datを確認しますか？ [y/n]: ");
    scanf("%63s", command); // *私的メモ
    if (strcmp(command, "y") == 0) {
      sfp = fopen("gifts.dat", "r");
      if (sfp == NULL)
	printf("ファイルをオープンできません.\n");
      else {
	while ((ch = fgetc(sfp)) != EOF)
	  putchar(ch);
	fclose(sfp);
      }
    }
  } while (strcmp(command, "y") != 0 && strcmp(command, "n") != 0);

  return SUCCESS;
}

/* 私的メモ
char型１文字を%cで読み取ると次のループに入ったときに
改行コードをバッファから読み取るので
１回文余分にループが回ってしまう。
*/
