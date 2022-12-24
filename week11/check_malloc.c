#include<stdio.h>
#include<stdlib.h>
#define MAX (1000000000)

int main() {

  int *p;
  int val;
  int i;

  do {
    printf("メモリを確保しますか[0/1]: ");
    scanf("%d", &val);
  } while (val != 0 && val != 1);
  if (val == 0)
    printf("メモリを確保しませんでした\n");
  else if (val == 1) {
    p = (int *)malloc(sizeof(int) * MAX);
    if (p == NULL) {
      printf("メモリを確保できません\n");
      return -1;
    }
    printf("メモリを確保しました\n");
  }

  do {
    printf("確保したメモリを使用しますか[0/1]: ");
    scanf("%d", &val);
  } while (val != 0 && val != 1);
  if (val == 0)
    printf("確保したメモリを使用しませんでした\n");
  else if (val == 1) {
    for (i = 0; i < MAX; i++)
      p[i] = i+1;
    printf("確保したメモリを使用しました\n");
  }

  do {
    printf("確保したメモリを開放しますか[0/1]: ");
    scanf("%d", &val);
  } while (val != 0 && val != 1);
  if (val == 0)
    printf("メモリを開放しませんでした\n");
  else if (val == 1) {
    free(p);
    printf("メモリを開放しました\n");
  }

  do {
    printf("開放したメモリを使用しますか[0/1]: ");
    scanf("%d", &val);
  } while (val != 0 && val != 1);
  if (val == 0)
    printf("開放したメモリを使用しませんでした\n");
  else if (val == 1) {
    for (i = 0; i < 1000000; i++)
      printf("%d\n", p[i]);
    printf("以下省略\n");
    printf("開放したメモリを使用しました\n");
  }

  do {
    printf("プログラムを終了します[1]: ");
    scanf("%d", &val);
  } while (val != 1);


  return 0;
}
