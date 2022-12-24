#include<stdio.h>

int main() {

  FILE *fp;
  FILE *ch_fp;
  FILE *prev_ch_fp;
  int ch; // fputc, fgetc を利用
  int prev_ch;
  int len = 0; // 文字数をカウント
  int th  = 0; // thの出現回数をカウント

  // キーボードからの入力をファイルに書き込むためにライトモードオープン
  fp = fopen("option04.txt", "w");
  if (fp == NULL) {
    printf("エラーが発生しました.\n");
    return -1;
  }

  printf("英文を入力してください\n");

  // キーボードから1文字ずつ読み込み、ファイルに書き込む
  while ((ch = fgetc(stdin)) != EOF)
    fputc(ch, fp);

  fclose(fp);

  // ファイルから文字を読み取るためリードモードオープン
  ch_fp = fopen("option04.txt", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }

  prev_ch_fp = fopen("option04.txt", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }

  ch = fgetc(ch_fp);
  prev_ch = fgetc(prev_ch_fp);
  // ファイルから読み取る
  while (ch != EOF) { // 1文字読み取りEOFまで読み取る

    if (  (ch == 't')   ||   (ch == 'T')  ) { // tなら
      len++; // tを文字数としてカウント
      ch = fgetc(ch_fp); // tの次の文字を読み込む
      if (ch == 'h') { // thなら
	printf("++"); // ++を印字
	th++; // thの出現回数をカウント
	prev_ch = fgetc(prev_ch_fp);
      }
      else { // 1文字目はtだが2文字目がhでないなら
	putchar(prev_ch); // t(T)を印字
	prev_ch = fgetc(prev_ch_fp);
	putchar(ch); // 読み取った文字(hではない文字)を印字
      }
    }
    else // t もしくは T ではないなら
      putchar(ch); // 読み取った文字(tではない文字)を印字


    // 改行文字以外の文字数をカウント
    if (ch != '\n')
      len++;

    ch = fgetc(ch_fp); // 次の文字を読み込む
    prev_ch = fgetc(prev_ch_fp);
  }

  printf("文字数: %d\n", len);
  printf("thの出現回数: %d\n", th);

  fclose(ch_fp);
  fclose(prev_ch_fp);

  return 0;
}
