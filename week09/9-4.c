#include<stdio.h>
#include<string.h>
#define LIST (16)
#define STR  (32)

void sort(char country[LIST][STR], char region[LIST][STR], int population[LIST]);

int main() {

  FILE *fp;
  int i = 0;
  char country[LIST][STR];
  char region[LIST][STR];
  int population[LIST];
  fp = fopen("countries16.dat", "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません\n");
    return -1;
  }
  while (fscanf(fp, "%s%s%d", country[i], region[i], &population[i]) == 3)
    i++;
  fclose(fp);

  sort(country, region, population);

  for (i = 0; i < LIST; i++)
    printf("%-10s %-10s %10d\n", country[i], region[i], population[i]);

  return 0;
}

void sort(char country[LIST][STR], char region[LIST][STR], int population[LIST]) {

  int i, j;
  char temp_country[STR];
  char temp_region[STR];
  int temp;

  for (i = LIST-1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (population[j] < population[j+1]) {
	// countryを入れ替え
	strcpy(temp_country, country[j]);
	strcpy(country[j], country[j+1]);
	strcpy(country[j+1], temp_country);
	// regionを入れ替え
	strcpy(temp_region, region[j]);
	strcpy(region[j], region[j+1]);
	strcpy(region[j+1], temp_region);
	// populationを入れ替え
	temp = population[j];
	population[j] = population[j+1];
	population[j+1] = temp;
      }
    }
  }

  return;
}
