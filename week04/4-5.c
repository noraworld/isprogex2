#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define STR (64)

int main() {

  FILE *fp;  // 2つのファイルを開かないときに使用
  FILE *sfp; // 2つのファイルを開くとき、元のファイルを開くときに使用
  FILE *dfp; // 2つのファイルを開くとき、新しいファイルを開くときに使用
  char command_yesno;
  int ch;
  int command_ope;
  char name[STR];
  char phone_num[STR];
  int i;
  int des;
  char search[STR];
  char dmy[STR];

  fp = fopen("telephone-directory.txt", "r");


  des = 0;
  // ファイルがなれけば新規作成するか確認する
  if (fp == NULL) {
    do {
      printf("電話帳が見つかりません. 新規作成しますか [y/n]: ");
      scanf("%c", &command_yesno);
      if (command_yesno != 'y' && command_yesno != 'n') {
	printf("不正な入力です.\n");
	scanf("%c", &command_yesno);
      }
    } while (command_yesno != 'y' && command_yesno != 'n');

    if (command_yesno == 'y') {
      fp = fopen("telephone-directory.txt", "w");
      fclose(fp);
      fp = fopen("telephone-directory.txt", "r");
      if (fp == NULL) {
	printf("エラーが発生しました.\n");
	return -1;
      }
      printf("新規作成しました.\n");
    }

    else {
      printf("電話帳は作成されていません.\n");
      return -1;
    }
  }

  
    // 電話帳ファイルを出力
    while ((ch = fgetc(fp)) != EOF)
      putchar(ch);

    fclose(fp); // 今後の操作によってモードが変わるので一旦クローズする

    do {
      puts("登録[1]");
      puts("検索[2]");
      puts("更新[3]");
      puts("削除[4]");
      puts("終了[5]");
      printf("どの操作を実行しますか: ");
      scanf("%d", &command_ope);
      if (command_ope <= 0 || command_ope >= 6)
	printf("正しいコマンドを入力してください.\n");
    } while (command_ope <= 0 || command_ope >= 6);


    des = 0;
    // データの登録
    if (command_ope == 1) {
      fp = fopen("telephone-directory.txt", "a");
      if (fp == NULL) {
	printf("エラーが発生しました.\n");
	return -1;
      }
      printf("登録したい人の名前を入力してください: ");
      fgets(dmy, sizeof(dmy)-1, stdin); // バッファの調整(scanfとの犬猿性を解消)
      fgets(name, sizeof(name)-1, stdin);
      i = 0;
      while (name[i] != '\n')
	i++;
      name[i] = '\0';
      do {
	printf("登録したい電話番号を入力してください(ハイフン不要): ");
	fgets(phone_num, sizeof(phone_num)-1, stdin);
	des = 1;
	i = 0;
	while (phone_num[i] != '\n')
	  i++;
	phone_num[i] = '\0';
	i = 0;
	while (phone_num[i] != '\0') {
	  if (isdigit(phone_num[i]) == 0) {
	    printf("すべて数字で入力してください.\n");
	    des = 0;
	    break;
	  }
	  i++;
	}
      } while (des == 0);

      fprintf(fp, "%-20s %s\n", name, phone_num);
      fclose(fp);
      printf("登録が完了しました.\n");
    }


    des = 0;
    // 検索
    if (command_ope == 2) {
      fp = fopen("telephone-directory.txt", "r");
      if (fp == NULL) {
	printf("エラーが発生しました.\n");
	return -1;
      }
      printf("検索したい人の名前を入力してください: ");
      fgets(dmy, sizeof(dmy)-1, stdin); // バッファの調整
      fgets(search, sizeof(search)-1, stdin);
      i = 0;
      while (search[i] != '\n')
	i++;
      search[i] = '\0';
      while (fscanf(fp, "%s%s", name, phone_num) == 2) {
	if (strcmp(search, name) == 0) {
	  printf("検索結果\n");
	  printf("%-20s %s\n", name, phone_num);
	  des = 1;
	}
      }
      if (des == 0)
	printf("該当する項目が見つかりませんでした.\n");
      fclose(fp);
    }


    des = 0;
    // 更新
    if (command_ope == 3) {
      sfp = fopen("telephone-directory.txt", "r");
      if (sfp == NULL) {
	printf("エラーが発生しました.\n");
	return -1;
      }
      dfp = fopen("telephone-directory.tmp", "w");
      if (dfp == NULL) {
	printf("エラーが発生しました.\n");
	return -1;
      }
      printf("変更したい人の名前を入力してください: ");
      fgets(dmy, sizeof(dmy)-1, stdin); // バッファの調整
      fgets(search, sizeof(search)-1, stdin);
      i = 0;
      while (search[i] != '\n')
	i++;
      search[i] = '\0';
      while (fscanf(sfp, "%s%s", name, phone_num) == 2) {
	if (strcmp(search, name) != 0)
	  fprintf(dfp, "%-20s %s\n", name, phone_num);
	else {
	  printf("変更後の名前を入力してください: ");
	  fgets(name, sizeof(name)-1, stdin);
	  i = 0;
	  while (name[i] != '\n')
	    i++;
	  name[i] = '\0';
	  do {
	    printf("変更後の電話番号を入力してください(ハイフン不要): ");
	    fgets(phone_num, sizeof(phone_num)-1, stdin);
	    des = 1;
	    i = 0;
	    while (phone_num[i] != '\n')
	      i++;
	    phone_num[i] = '\0';
	    i = 0;
	    while (phone_num[i] != '\0') {
	      if (isdigit(phone_num[i]) == 0) {
		printf("すべて数字で入力してください.\n");
		des = 0;
		break;
	      }
	      i++;
	    }
	  } while (des == 0);
	    fprintf(dfp, "%-20s %s\n", name, phone_num);
	    des = 2;
	  }
      }
      if (des != 2)
	printf("該当する項目が見つかりませんでした.\n");
      else
	printf("更新が完了しました.\n");
      fclose(sfp);
      fclose(dfp);
      remove("telephone-directory.txt");
      rename("telephone-directory.tmp", "telephone-directory.txt");
    }


    des = 0;
    // 削除
    if (command_ope == 4) {
      sfp = fopen("telephone-directory.txt", "r");
      dfp = fopen("telephone-directory.tmp", "w");
      if (sfp == NULL) {
	printf("エラーが発生しました.\n");
	return -1;
      }
      if (dfp == NULL) {
	printf("エラーが発生しました.\n");
	return -1;
      }
      printf("削除したい人の名前を入力してください: ");
      fgets(dmy, sizeof(dmy)-1, stdin); // バッファの調整
      fgets(search, sizeof(search)-1, stdin);
      i = 0;
      while (search[i] != '\n')
	i++;
      search[i] = '\0';
      while (fscanf(sfp, "%s%s", name, phone_num) == 2) {
	if (strcmp(search, name) != 0)
	  fprintf(dfp, "%-20s %s\n", name, phone_num);
	else
	  des = 1;
      }
      if (des != 1)
	printf("該当する項目が見つかりませんでした.\n");
      else
	printf("削除が完了しました.\n");
      fclose(sfp);
      fclose(dfp);
      remove("telephone-directory.txt");
      rename("telephone-directory.tmp", "telephone-directory.txt");
    }

    // 終了(ここはなくても良い)
    /*
    if (command_ope == 5) {

    }
    */
  
    
    return 0;
}
