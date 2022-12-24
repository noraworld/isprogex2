#include<stdio.h>
#include<stdlib.h>
#define GENERATE (1000000) // <- 任意のデータ数(※)

int main() {

  double val;
  int i;

  FILE *fp;
  fp = fopen("numbers1M.dat", "w"); // <- 任意のファイル名(※)
  fprintf(fp, "%d\n", GENERATE);
  for (i = 0; i < GENERATE; i++) {
    val = rand() % (GENERATE*10-1) + 1;
    val = val / (GENERATE*10);
    fprintf(fp, "%.7f\n", val); // <- データ数に応じた値(※)
  }
  fclose(fp);

  return 0;
}

// ※※※※※※※※※※※※※※※ //
//                                //
//    GENERATE  filename  figure  //
//     1000000        1M       7  //
//    10000000       10M       8  //
//   100000000      100M       9  //
//  1000000000        1G      10  //
//                                //
//    これ以上は処理が長くなる    //
//                                //
// ※※※※※※※※※※※※※※※ //
