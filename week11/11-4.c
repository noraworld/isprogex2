#include<stdio.h>
#include<sys/time.h> // gettimeofday()を使用
#include<stdlib.h>   // malloc()を使用

// 処理時間を取得する
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
  double start, end; // start->処理開始時の経過時間, end->処理終了時の経過時間

  for (i = 0; i < memory; i++)
    temp_ary[i] = ary[i];
  start = gettimeofday_sec();    // 処理時間計測開始
  select_sort(temp_ary, memory);
  end = gettimeofday_sec();      // 処理時間計測終了
  printf("　　選択ソートの処理時間: %24.20f\n", (end - start));
  fp = fopen("select_sort.dat", "w"); // ソートの結果はファイルに出力
  for (i = 0; i < memory; i++)
    fprintf(fp, "%f\n", temp_ary[i]);
  fclose(fp);

  for (i = 0; i < memory; i++)
    temp_ary[i] = ary[i];
  start = gettimeofday_sec();
  insert_sort(temp_ary, memory);
  end = gettimeofday_sec();
  printf("　　挿入ソートの処理時間: %24.20f\n", (end - start));
  fp = fopen("insert_sort.dat", "w");
  for (i = 0; i < memory; i++)
    fprintf(fp, "%f\n", temp_ary[i]);
  fclose(fp);

  for (i = 0; i < memory; i++)
    temp_ary[i] = ary[i];
  start = gettimeofday_sec();
  bubble_sort(temp_ary, memory);
  end = gettimeofday_sec();
  printf("　バブルソートの処理時間: %24.20f\n", (end - start));
  fp = fopen("bubble_sort.dat", "w");
  for (i = 0; i < memory; i++)
    fprintf(fp, "%f\n", temp_ary[i]);
  fclose(fp);

  for (i = 0; i < memory; i++)
    temp_ary[i] = ary[i];
  start = gettimeofday_sec();
  heap_sort(temp_ary, memory);
  end = gettimeofday_sec();
  printf("　ヒープソートの処理時間: %24.20f\n", (end - start));
  fp = fopen("heap_sort.dat", "w");
  for (i = 0; i < memory; i++)
    fprintf(fp, "%f\n", temp_ary[i]);
  fclose(fp);

  for (i = 0; i < memory; i++)
    temp_ary[i] = ary[i];
  start = gettimeofday_sec();
  marge_sort(temp_ary, 0, memory-1);
  end = gettimeofday_sec();
  printf("　マージソートの処理時間: %24.20f\n", (end - start));
  fp = fopen("marge_sort.dat", "w");
  for (i = 0; i < memory; i++)
    fprintf(fp, "%f\n", temp_ary[i]);
  fclose(fp);

  for (i = 0; i < memory; i++)
    temp_ary[i] = ary[i];
  start = gettimeofday_sec();
  quick_sort(temp_ary, 0, memory-1);
  end = gettimeofday_sec();
  printf("クイックソートの処理時間: %24.20f\n", (end - start));
  fp = fopen("quick_sort.dat", "w");
  for (i = 0; i < memory; i++)
    fprintf(fp, "%f\n", temp_ary[i]);
  fclose(fp);

  free(ary);
  free(temp_ary);

  return 0;
}
