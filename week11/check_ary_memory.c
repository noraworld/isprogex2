#include<stdio.h>
#define MAX (2000000) // <- なぜか2095570以上にするとSegmentation fault

int main() {

  int a[MAX];
  int i;
  int val;

  do {
    printf("配列を定義しました[0/1]: ");
    scanf("%d", &val);
  } while (val != 0 && val != 1);
  if (val == 0)
    return 0;
  else if (val == 1)
    for (i = 0; i < MAX; i++)
      a[i] = i+1;

  do {
    printf("配列を使用しました[0/1]: ");
    scanf("%d", &val);
  } while (val != 0 && val != 1);
  if (val == 0)
    return 0;
  else if (val == 1)
    for (i = 0; i < MAX; i++)
      printf("%d\n", a[i]);

  do {
    printf("配列を表示しました[0]: ");
    scanf("%d", &val);
  } while (val != 0);

  return 0;
}
