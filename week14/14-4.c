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

int delete(struct node **table, int key);
void print_hash(struct node **table);
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
  int del;
  print_hash(table);
  while (1) {
    printf("削除する値を入力してください: ");
    scanf("%d", &del);
    if (del < 0)
      break;
    temp = delete(table, del);
    switch (temp) {
    case 0: printf("%dはありません.\n", del); break;
    case 1:
      printf("%dを削除しました.\n", del);
      print_hash(table);
      break;
    }
  }

  for (i = 0; i < DIVISOR; i++)
    free_hash(table[i]);

  return 0;
}

int delete(struct node **table, int key) {

  struct node *temp_back, *temp;
  int mod;

  mod = key % DIVISOR;
  temp = table[mod];
  temp_back = table[mod];

  if (temp->next != NULL) {
    if (temp->key == key) {
      *temp = *temp->next;
      temp_back = NULL;
      return 1;
    }
  }
  while (temp != NULL) {
    temp = temp->next;
    if (temp->key == key) {
      temp_back->next = temp_back->next->next;
      temp = NULL;
      return 1;
    }
    temp_back = temp_back->next;
  }

  return 0;
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

void free_hash(struct node *table) {
  if (table != NULL) {
    free_hash(table->next);
    free(table);
  }
}
