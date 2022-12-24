#include<stdio.h>

typedef struct {
  char code[32];
  char name[32];
  int price;
} gift;

int main() {

  gift data = {"JZK-30", "Jizake_tsumeawase", 4500};

  printf("code: %s\n", data.code);
  printf("name: %s\n", data.name);
  printf("price: %d\n", data.price);

  return 0;
}
