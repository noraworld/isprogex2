#include<stdio.h>

int main() {

  FILE *fp;
  int ch;
  char fname[64];

  fp = fopen("helloworld.txt", "r");

  if (fp == NULL)
    printf("ファイルをオープンできません.\n");
  else {
    while ((ch = fgetc(fp)) != EOF)
      putchar(ch);
    fclose(fp);
  }

  return 0;
}
