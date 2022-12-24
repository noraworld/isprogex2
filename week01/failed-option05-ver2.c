#include<stdio.h>
#include<ctype.h>
#define SUCCESS (0)
#define FALSE (-1)
#define SIZE (256)

int main() {

  FILE *sfp;
  FILE *dfp;
  int ch;

  // ファイルをオープンする
  sfp = fopen("gifts.dat", "r");
  if (sfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FALSE;
  }

  dfp = fopen("gifts2.dat", "w");
  if (dfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FALSE;
  }

  // gifts.dat内の小文字を大文字に変換してgifts2.datに書き込む
  while ((ch = fgetc(sfp)) != EOF) {
    ch = toupper(ch);
    fputc(ch, dfp);
  }

  // ファイルをクローズする
  fclose(sfp);
  fclose(dfp);

  // ファイルをオープンする
  dfp = fopen("gifts2.dat", "r");
  if (dfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FALSE;
  }

  // ファイルの内容を印字する
  while ((ch = fgetc(dfp)) != EOF)
    putchar(ch);

  // ファイルをクローズする
  fclose(dfp);


  return SUCCESS;
}
