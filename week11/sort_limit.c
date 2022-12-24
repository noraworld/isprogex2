#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

double gettimeofday_sec() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main() {

  double *ary;
  FILE *fp;

  char filename[32];
  printf("ファイル名: ");
  scanf("%s", filename);
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }

  int memory;
  fscanf(fp, "%d", &memory);
  ary = (double *)malloc(sizeof(double) * memory);
  if (ary == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }

  unsigned i = 0;
  while (fscanf(fp, "%lf", &ary[i]) == 1)
    i++;
  fclose(fp);

  double *temp_ary;
  temp_ary = (double *)malloc(sizeof(double) * memory);
  if (temp_ary == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  double start, end;

  int kind = 0;
  do {
    printf("　　選択ソート: [1]\n");
    printf("　　挿入ソート: [2]\n");
    printf("　バブルソート: [3]\n");
    printf("　ヒープソート: [4]\n");
    printf("　マージソート: [5]\n");
    printf("クイックソート: [6]\n");
    printf("ソート番号: ");
    scanf("%d", &kind);
  } while (kind <= 0 || kind >= 7);

  if (kind == 1) {
    for (i = 0; i < memory; i++)
      temp_ary[i] = ary[i];
    start = gettimeofday_sec();
    select_sort(temp_ary, memory);
    end = gettimeofday_sec();
    printf("選択ソートの処理時間: %24.20f\n", (end - start));
    fp = fopen("sort_limit.dat", "w");
    fprintf(fp, "%d\n", memory);
    for (i = 0; i < memory; i++)
      fprintf(fp, "%.10f\n", temp_ary[i]);
    fclose(fp);
  }

  if (kind == 2) {
    for (i = 0; i < memory; i++)
      temp_ary[i] = ary[i];
    start = gettimeofday_sec();
    insert_sort(temp_ary, memory);
    end = gettimeofday_sec();
    printf("挿入ソートの処理時間: %24.20f\n", (end - start));
    fp = fopen("sort_limit.dat", "w");
    fprintf(fp, "%d\n", memory);
    for (i = 0; i < memory; i++)
      fprintf(fp, "%.10f\n", temp_ary[i]);
    fclose(fp);
  }

  if (kind == 3) {
    for (i = 0; i < memory; i++)
      temp_ary[i] = ary[i];
    start = gettimeofday_sec();
    bubble_sort(temp_ary, memory);
    end = gettimeofday_sec();
    printf("バブルソートの処理時間: %24.20f\n", (end - start));
    fp = fopen("sort_limit.dat", "w");
    fprintf(fp, "%d\n", memory);
    for (i = 0; i < memory; i++)
      fprintf(fp, "%.10f\n", temp_ary[i]);
    fclose(fp);
  }

  if (kind == 4) {
    for (i = 0; i < memory; i++)
      temp_ary[i] = ary[i];
    start = gettimeofday_sec();
    heap_sort(temp_ary, memory);
    end = gettimeofday_sec();
    printf("ヒープソートの処理時間: %24.20f\n", (end - start));
    fp = fopen("sort_limit.dat", "w");
    fprintf(fp, "%d\n", memory);
    for (i = 0; i < memory; i++)
      fprintf(fp, "%.10f\n", temp_ary[i]);
    fclose(fp);
  }

  if (kind == 5) {
    for (i = 0; i < memory; i++)
      temp_ary[i] = ary[i];
    start = gettimeofday_sec();
    marge_sort(temp_ary, 0, memory-1);
    end = gettimeofday_sec();
    printf("マージソートの処理時間: %24.20f\n", (end - start));
    fp = fopen("sort_limit.dat", "w");
    fprintf(fp, "%d\n", memory);
    for (i = 0; i < memory; i++)
      fprintf(fp, "%.10f\n", temp_ary[i]);
    fclose(fp);
  }

  if (kind == 6) {
    for (i = 0; i < memory; i++)
      temp_ary[i] = ary[i];
    start = gettimeofday_sec();
    quick_sort(temp_ary, 0, memory-1);
    end = gettimeofday_sec();
    printf("クイックソートの処理時間: %24.20f\n", (end - start));
    fp = fopen("sort_limit.dat", "w");
    fprintf(fp, "%d\n", memory);
    for (i = 0; i < memory; i++)
      fprintf(fp, "%.10f\n", temp_ary[i]);
    fclose(fp);
  }

  free(ary);
  free(temp_ary);

  return 0;
}
