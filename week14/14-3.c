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

int insert(struct node **table, int key);
void print_hash(struct node **table);
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

  int temp = 2;
  int ins;
  print_hash(table);
  while (1) {
    printf("追加する値を入力してください: ");
    scanf("%d", &ins);
    if (ins < 0)
      break;
    temp = insert(table, ins);
    switch (temp) {
    case 0: printf("%dはすでに存在します.\n", ins); break;
    case 1:
      printf("%dを追加しました.\n", ins);
      print_hash(table);
      break;
    }
  }

  for (i = 0; i < DIVISOR; i++)
    free_hash(table[i]);

  return 0;
}

int insert(struct node **table, int key) {

  struct node *p = NULL;
  struct node *temp;
  int mod;

  // 同じデータが含まれていないか探索して確認する
  temp = member(table, key);
  if (temp != NULL)
    return 0;

  mod = key % DIVISOR;
  p = (struct node *)malloc(sizeof(struct node));
  if (p == NULL) {
    printf("メモリを確保できません.\n");
    return -1;
  }
  p->key = key;
  p->next = table[mod];
  table[mod] = p;

  return 1;
}

void print_hash(struct node **table) {

  struct node *temp[DIVISOR];
  int i;

  for (i = 0; i < DIVISOR; i++)
    temp[i] = table[i];

  for (i = 0; i < DIVISOR; i++) {
    printf("%d: ", i);
    while (temp[i] != NULL) {
      printf("%2d", temp[i]->key);
      if (temp[i]->next != NULL)
	printf(" -> ");
      temp[i] = temp[i]->next;
    }
    putchar('\n');
  }

  return;
}

struct node *member(struct node **table, int key) {

  struct node *temp[DIVISOR];
  int mod, i;

  for (i = 0; i < DIVISOR; i++)
    temp[i] = table[i];

  mod = key % DIVISOR;
  while (temp[mod] != NULL) {
    if (temp[mod]->key == key)
      return temp[mod];
    temp[mod] = temp[mod]->next;
  }

  return NULL;
}

void free_hash(struct node *table) {
  if (table != NULL) {
    free_hash(table->next);
    free(table);
  }
}
