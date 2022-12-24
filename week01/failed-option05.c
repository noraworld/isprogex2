#include<stdio.h>
#include<ctype.h>
#define SUCCESS (0)
#define FALSE (-1)
#define TRUE (1)
#define ELEMENT (64)

int main() {

  FILE *sfp;
  FILE *dfp;
  char code[ELEMENT];
  char name[ELEMENT];
  int price;
  int ch;

  sfp = fopen("gifts.dat", "r");
  if (sfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FALSE;
  }

  dfp = fopen("gifts2.dat", "w");
  if (dfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FALSE;
  }

  while (TRUE) {
    if (fscanf(sfp, "%s%s%d", code, name, &price) == 3) {
      fprintf(dfp, "%s %-17s %d\n", code, name, price);
      printf("%s %-17s %d\n", code, name, price);
    }
    else if (fscanf(sfp, "%s%s", code, name) == 2) {
      fprintf(dfp, "%s %-17s xxxx\n", code, name);
      printf("%s %-17s xxxx\n", code, name);
    }
    else
      break;
  }

  fclose(sfp);
  fclose(dfp);

  dfp = fopen("gifts2.dat", "r");
  if (dfp == NULL) {
    printf("ファイルをオープンできません.\n");
    return FALSE;
  }

  while ((ch = fgetc(dfp)) != EOF)
    putchar(ch);

  fclose(dfp);

  return SUCCESS;
}
