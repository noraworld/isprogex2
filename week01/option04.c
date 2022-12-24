#include<stdio.h>
#define GIFT (32)
#define DATA (4)

typedef struct {
  char code[GIFT];
  char name[GIFT];
  int price;
} gift;

int main() {

  FILE *fp;
  gift data[DATA];
  int i = 0;

  fp = fopen("gifts.dat", "r");
  if (fp == NULL)
    printf("ファイルをオープンできません.\n");
  else {
    while (fscanf(fp, "%s%s%d", data[i].code, data[i].name, &data[i].price) == 3)
      i++;
    fclose(fp);

    for (i = 0; i < DATA; i++) {
      printf("code: %s\n", data[i].code);
      printf("name: %s\n", data[i].name);
      printf("price: %d\n", data[i].price);
      if (i < DATA - 1)
	putchar('\n');
    }
  }

  return 0;
}
