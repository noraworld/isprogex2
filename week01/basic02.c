#include<stdio.h>
#define SUCCESS (0)
#define FAILED (-1)

int main() {

  FILE *fp;

  fp = fopen("helloworld.txt", "w");
  if (fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FAILED;
  }

  fprintf(fp,
"Hello world !!\n"
"When I woke up this morning, I found many people in my room.\n"
	  "What's up ?: -0\n");
  fclose(fp);

  printf("ファイルへの出力が正常に完了しました.\n");

  return SUCCESS;
}
