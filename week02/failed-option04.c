#include<stdio.h>

int main() {

  int len = 0; // 文字数(改行コード除く)をカウントする変数
  int th = 0; // thの出現回数をカウントする変数
  int c; // getcharで読み込んだ文字を返し、putcharで標準出力に印字するための変数

  printf("英文を入力してください.\n");

  c = getchar(); // 最初の1文字目を読み込む

  while (c != EOF) {



    if (  (c == 't')   ||   (c == 'T')  ) { // tなら
      len++; // tを文字数としてカウント
      c = getchar(); // tの次の文字を読み込む
      if (c == 'h') { // thなら
	printf("++"); // ++を印字
	th++; // thの出現回数をカウント
      }
      else { // 1文字目はtだが2文字目がhでないなら
	putchar('t'); // tを印字
	putchar(c); // 読み取った文字(hではない文字)を印字
      }
    }
    else // t もしくは T ではないなら
      putchar(c); // 読み取った文字(tではない文字)を印字



    // 改行文字以外の文字数をカウント
    if (c != '\n')
      len++;

    c = getchar(); // 次の文字を読み込む
  } // Matches while (c != EOF) {

  printf("文字数: %d\n", len);
  printf("thの出現回数: %d\n", th);

  return 0;
}

/* 
テキストファイルから読み取るにはリダイレクション(>)を使用する
あらかじめテキストファイルに文字を書いておきコマンドプロンプトで

$ ./option04 > text.txt

のように実行する


キーボードから読み取るにはヒアドキュメント(<<)を使用する
【実行例】
$ ./option04 << EOT
> We have seen other things matter.
> But, that is the thing that matters.
> EOT
We have seen o++er ++ings matter.
But, ++at is ++e ++ing ++at matters.
文字数: 69
thの出現回数: 6
$

※ << EOT の "EOT" は任意の文字または文字列(EOT は End Of Text)
*/
