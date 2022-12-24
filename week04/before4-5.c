#include<stdio.h>

int main() {

  FILE *fp;
  FILE *fp2;
  int ch;
  int command;
  char left[256];
  char right[256];


  fp = fopen("before4-5.txt", "w");

  fprintf(fp,
"ritsumei 09011112222\n"
"kinugasa 09022223333\n"
"bkc      09033334444\n"
"suzaku   09044445555\n"
"ibaraki  09055556666\n"
	  );

  fclose(fp);
  fp = fopen("before4-5.txt", "r");

  while ((ch = fgetc(fp)) != EOF)
    putchar(ch);

  fclose(fp);

  printf("コマンド: ");
  scanf("%d", &command);

  // 登録
  if (command == 1) {
    fp = fopen("before4-5.txt", "a");
    fprintf(fp, "touroku  09066667777\n");
  }

  // 検索
  if (command == 2) {
    fp = fopen("before4-5.txt", "r");
    while (fscanf(fp, "%s%s", left, right) == 2) {
      if (strcmp(left, "bkc") == 0)
	printf("%s %s\n", left, right);
    }
    fclose(fp);
  }

  // 更新（変更）
  if (command == 3) {
    fp = fopen("before4-5.txt", "r");
    fp2 = fopen("before4-5.tmp", "w");
    while (fscanf(fp, "%s%s", left, right) == 2) {
      if (strcmp(left, "kinugasa") != 0)
	fprintf(fp2, "%s %s\n", left, right);
      else
	fprintf(fp2, "xxxxxxxx ccccccccccc\n");
    }
    fclose(fp);
    fclose(fp2);
    remove("before4-5.txt"); // 元のファイルを削除
    rename("before4-5.tmp", "before4-5.txt"); // 変更後のファイルを元のファイル名に
  }

  // 削除
  if (command == 4) {
    fp = fopen("before4-5.txt", "r");
    fp2 = fopen("before4-5.tmp", "w");
    while (fscanf(fp, "%s%s", left, right) == 2) {
      if (strcmp(left, "suzaku") != 0)
	fprintf(fp2, "%s %s\n", left, right);
    }
    fclose(fp);
    fclose(fp2);
    remove("before4-5.txt"); // 元のファイルを削除
    rename("before4-5.tmp", "before4-5.txt"); // 変更後のファイルを元のファイル名に
  }

  /* 更新と削除に関して
別ファイルを用意する。
更新、削除したい行じゃなければふつうにコピーすればよい
更新、削除したい行にきたら、そこだけ変更、削除したものをファイルに出力すればよい
最後に、元のファイルを削除してから一時的につくった別ファイルの名前を元のファイル名にする
  */

  return 0;
}
