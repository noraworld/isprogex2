// divisor 除数
// mod 余り

#include<stdio.h>
#include<stdlib.h>
#define DIVISOR (5)
#define NODE_NUM (10)

struct node {
  int key;
  struct node *next;
};

struct node *member(struct node **table, int key);
void free_hash(struct node *table);

int main() {

  struct node *table[DIVISOR] = {NULL, NULL, NULL, NULL, NULL};
  struct node *p = NULL;
  int key[NODE_NUM] = {18, 9, 22, 4, 21, 12, 15, 31, 7, 25};
  int mod, i;

  for (i = 0; i < NODE_NUM; i++) {
    mod = key[i] % DIVISOR;
    p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
      printf("メモリを確保できません.\n");
      return -1;
    }
    p->key = key[i];
    p->next = table[mod];
    table[mod] = p;
  }

  struct node *temp; // 探索した結果(ノード or NULL)を代入する
  int mem;
  printf("探索する値を入力してください: ");
  scanf("%d", &mem);
  if (mem >= 0) {
    temp = member(table, mem);
    if (temp != NULL)
      printf("%dは見つかりました.\n", temp->key);
    else
      printf("%dは見つかりませんでした.\n", mem);
  }
  else
    printf("正の数を入力してください.\n");

  for (i = 0; i < DIVISOR; i++)
    free_hash(table[i]);

  return 0;
}

struct node *member(struct node **table, int key) {

  struct node *temp;
  int mod, i;

  mod = key % DIVISOR;
  temp = table[mod];

  while (temp != NULL) {
    if (temp->key == key)
      return temp;
    temp = temp->next;
  }

  return NULL;
}

void free_hash(struct node *table) {
  if (table != NULL) {
    free_hash(table->next);
    free(table);
  }
}
