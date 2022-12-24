#include<stdio.h>

int main() {

  FILE *fp;
  char type[256];
  char name[256];
  int price;

  fp = fopen("gifts.dat", "r");

  if (fp == NULL)
    printf("ファイルをオープンできません.\n");
  else {
    while (fscanf(fp, "%s%s%d", type, name, &price) == 3)
      printf("%s %-17s %d\n", type, name, price);
    fclose(fp);
  }

  return 0;
}
