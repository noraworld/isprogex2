#include<stdio.h>
#include<string.h>

typedef struct word_pair {
  char longer_word[10];    // 長い方の文字列
  char shorter_word[10];   // 短い方の文字列
  char combined_word[20];  // 連結した文字列
  int longer_word_length;  // 長い方の文字列の長さ
  int shorter_word_length; // 短い方の文字列の長さ
} word_pair_t;

word_pair_t create_word_pair(char *a, char *b); // 構造体にデータをセットする関数

int main() {

  char a[10];
  char b[10];
  int i;
  word_pair_t data; // 構造体

  printf("文字列aを入力してください: ");
  fgets(a, sizeof(a)-1, stdin);
  printf("文字列bを入力してください: ");
  fgets(b, sizeof(b)-1, stdin);

  // fgetsで生成された改行コードをナル文字に上書き(配列a)
  i = 0;
  while (a[i] != '\n')
    i++;
  a[i] = '\0';

  // fgetsで生成された改行コードをなる文字に上書き(配列b)
  i = 0;
  while (b[i] != '\n')
    i++;
  b[i] = '\0';

  data = create_word_pair(a, b); // create_word_pair関数にアドレスを渡す

  printf("長い方の文字列は%sです.\n", data.longer_word);
  printf("短い方の文字列は%sです.\n", data.shorter_word);
  printf("連結した文字列は%sです.\n", data.combined_word);
  printf("長い方の文字列の長さは%dです.\n", data.longer_word_length);
  printf("短い方の文字列の長さは%dです.\n", data.shorter_word_length);

  return 0;
}

// strcmpは長さの区別自体はできない

word_pair_t create_word_pair(char *a, char *b) {

  word_pair_t data; // 構造体
  int a_length; // 配列aの長さ
  int b_length; // 配列bの長さ
  char *p_longer;  // 長い方の文字列を指すポインタ
  char *p_shorter; // 短い方の文字列を指すポインタ
  int i;

  // 長さを計算
  a_length = strlen(a);
  b_length = strlen(b);

  // 長い方をdata.longer_word_lengthに、短い方をdata.shorter_word_lengthに代入
  if (a_length >= b_length) { // aが長ければ
    data.longer_word_length = a_length;
    data.shorter_word_length = b_length;
    p_longer = a;
    p_shorter = b;
  }
  else { // bが長ければ
    data.longer_word_length = b_length;
    data.shorter_word_length = a_length;
    p_longer = b;
    p_shorter = a;
  }

  // 長い文字列をdata.longer_wordに、短い文字列をdata.shorter_wordに代入
  if (data.longer_word_length != data.shorter_word_length) { // 長さが異なれば
    strcpy(data.longer_word, p_longer);
    strcpy(data.shorter_word, p_shorter);
  }
  else { // 長さが一致していれば
    if (strcmp(a, b) > 0) { // aが辞書順で遅ければ
      strcpy(data.longer_word, a);
      strcpy(data.shorter_word, b);
      p_longer = a;
      p_shorter = b;
    }
    else if (strcmp(a, b) < 0) { // aが辞書順で早ければ
      strcpy(data.longer_word, b);
      strcpy(data.shorter_word, a);
      p_longer = b;
      p_shorter = a;
    }
    else { // aとbが完全に一致していれば
      printf("文字列aと文字列bが完全に一致しています.\n");
      strcpy(data.longer_word, a);
      data.shorter_word[0] = '\0';
    }
  }

  // aとbを連結させる
  strcpy(data.combined_word, p_longer);
  strcat(data.combined_word, " ");
  strcat(data.combined_word, p_shorter);
  // aの文字列とbの文字列の間にスペースを入れる　※
  /*
  i = strlen(data.combined_word) + 1;
  while (i != data.longer_word_length-1) {
    data.combined_word[i+1] = data.combined_word[i];
    i--;
  }
  data.combined_word[i+1] = 32; // スペース代入 (ASCII(32) = ' ')
  */

  return data; // 構造体を返却

  /* ※
文字列の後ろ側（ナル文字）から前に向かって調べていく。
一つ前の文字を次の文字に順々にコピーしていき、
aの文字列まできたらコピーをやめる。
するとaの文字列とbの文字列の間には次の文字と同じ文字が格納されているので
その要素をスペースに置き換えてaとbの文字列の間にスペースを代入している。
   */
}
