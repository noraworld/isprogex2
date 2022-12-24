#include<stdio.h>

int main() {

  char c, *p;
  char s[12] = "Ritsumeikan";

  c = 'A';
  p = &c;                            // ポインタpがchar型変数cのアドレスを指す
  printf("c: %c\n", c);              // char型変数cに格納されている値（A）を表示する
  printf("&c: %p\n\n", &c);          // char型変数cのアドレスを表示する
  printf("p: %p\n", p);              // char型変数cのアドレスを表示する
  printf("*p: %c\n\n", *p);          // char型変数cに格納されている値（A）を表示する

  *p = 'B';
  printf("c: %c\n", c);              // char型変数cに格納されている値（B）を表示する
  printf("&c: %p\n\n", &c);          // char型変数cのアドレスを表示する
  printf("p: %p\n", p);              // char型変数cのアドレスを表示する
  printf("*p: %c\n\n", *p);          // char型変数cに格納されている値（B）を表示する

  printf("s: %s\n", s);              // char型配列sに格納されている11文字を表示する
  printf("s[0]: %c\n", s[0]);        // char型配列sに格納されている0番目の要素（左から1個目の文字）を表示する
  printf("s[1]: %c\n", s[1]);        // char型配列sに格納されている1番目の要素（左から2個目の文字）を表示する
  printf("s: %p\n", s);              // char型配列sの0番目の要素におけるアドレスを表示する
  printf("&s[0]: %p\n", &s[0]);      // char型配列sの0番目の要素におけるアドレスを表示する
  printf("*s: %c\n", *s);            // char型配列sに格納されている0番目の要素（左から1個目の文字）を表示する
  printf("*(s+1): %c\n\n", *(s+1));  // char型配列sに格納されている1番目の要素（左から2個目の文字）を表示する

  *(s+2) = 'T';                      // char型配列sに格納されている2番目の要素（左から3個目の文字）'t'を'T'に変更する
  printf("s: %s\n", s);              // char型配列sに格納されている11文字を表示する（RiTsumeikan）

  return 0;
}
