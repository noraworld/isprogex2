#include<stdio.h>

int main() {

  int a, *p;

  a = 10;
  printf("a: %d\n", a);      // 変数aに格納されている値（10）を表示する
  printf("&a: %p\n\n", &a);  // 変数aのアドレスを表示する

  p = &a;                    // ポインタpがaのアドレスを指す
  printf("p: %p\n", p);      // 変数aのアドレスを表示する
  printf("*p: %d\n", *p);    // 変数aに格納されている値（10）を表示する
  printf("&p: %p\n\n", &p);  // ポインタpのアドレスを表示する

  a = 20;
  printf("a: %d\n", a);      // 変数aに格納されている値（20）を表示する
  printf("&a: %p\n\n", &a);  // 変数aのアドレスを表示する

  printf("p: %p\n", p);      // 変数aのアドレスを表示する
  printf("*p: %d\n", *p);    // 変数aに格納されている値（20）を表示する
  printf("&p: %p\n", &p);    // ポインタpのアドレスを表示する

  return 0;
}
