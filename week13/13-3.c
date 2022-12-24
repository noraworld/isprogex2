#include<stdio.h>
#include<stdlib.h>
#define TRUE (1)

struct node {
  int key;
  struct node *parent, *left, *right;
};

void free_tree(struct node *node);
struct node *new_node(int key);

int delete(int key, struct node *root) {
  struct node *temp;
  int det;

  if (root->key == 0)
    return 0;
  else if (root->key == key) {
    // 削除対象ノードの右子・左子ともに外点のとき
    if (root->left->key == 0 && root->right->key == 0) {
      root->key = 0;
      free(root->left);
      free(root->right);
      root->left = NULL;
      root->right = NULL;
    }
    // 削除対象ノードの左子が内点のとき
    else if (root->left->key != 0 && root->key != 0) {
      temp = root;
      temp = temp->left;
      while (temp->right->key != 0)
	temp = temp->right;
      root->key = temp->key;
      temp->key = 0;
      if (temp->left != 0)
	*temp = *(temp->left);
      else {
	free(temp->left);
	free(temp->right);
	temp->left = NULL;
	temp->right = NULL;
      }
    }
    // 削除対象ノードの右子が内点のとき
    else if (root->left->key == 0 && root->right->key != 0 && root->key != 0) {
      temp = root;
      temp = temp->right;
      while (temp->left->key != 0)
	temp = temp->left;
      root->key = temp->key;
      temp->key = 0;
      if (temp->right != 0)
	*temp = *(temp->right);
      else {
	free(temp->left);
	free(temp->right);
	temp->left = NULL;
	temp->right = NULL;
      }
    }
    return 1;
  }
  else if (root->key > key)
    det = delete(key, root->left);
  else if (root->key < key)
    det = delete(key, root->right);

  return det;
}

struct node *new_node(int key) {
  struct node *p;

  // 構造体のメモリを確保してキーを代入をする
  p = (struct node *)malloc(sizeof(struct node));
  p->key = key;
  p->left = NULL;
  p->right = NULL;
  p->parent = NULL;

  return p;  //ただし p は当該関数内で定義された struct node 型のポインタ
}

void free_tree(struct node *node) {
  if (node != NULL) {
    free_tree(node->left);
    free_tree(node->right);
    free(node);
  }
}

int main() {

  struct node *root, *n[10];

  n[0] = new_node(4);
  n[1] = new_node(7);
  n[2] = new_node(9);
  n[3] = new_node(12);
  n[4] = new_node(15);
  n[5] = new_node(18);
  n[6] = new_node(21);
  n[7] = new_node(22);
  n[8] = new_node(25);
  n[9] = new_node(31);

  root = n[5];

  // 外点には0を代入する(rootの親は存在しないからNULL)
  n[0]->left = new_node(0);
  n[0]->right = n[1];
  n[0]->parent = n[2];

  n[1]->left = new_node(0);
  n[1]->right = new_node(0);
  n[1]->parent = n[0];

  n[2]->left = n[0];
  n[2]->right = n[3];
  n[2]->parent = n[5];

  n[3]->left = new_node(0);
  n[3]->right = n[4];
  n[3]->parent = n[2];

  n[4]->left = new_node(0);
  n[4]->right = new_node(0);
  n[4]->parent = n[3];

  n[5]->left = n[2];
  n[5]->right = n[7];
  n[5]->parent = NULL;

  n[6]->left = new_node(0);
  n[6]->right = new_node(0);
  n[6]->parent = n[7];

  n[7]->left = n[6];
  n[7]->right = n[9];
  n[7]->parent = n[5];

  n[8]->left = new_node(0);
  n[8]->right = new_node(0);
  n[8]->parent = n[9];

  n[9]->left = n[8];
  n[9]->right = new_node(0);
  n[9]->parent = n[7];

  // アルゴリズム第９章の演習課題(5/5)のケース
  //root->left->right->right->left = new_node(13);
  //root->left->right->right->left->left = new_node(0);
  //root->left->right->right->left->right = new_node(0);
  int key;
  int det;
  print_tree(root);
  while (TRUE) {
    printf("削除するキーを入力してください: ");
    scanf("%d", &key);
    if (key <= 0)
      break;
    det = delete(key, root);
    switch (det) {
    case 0 : printf("%dはノードに存在しません.\n", key); break;
    case 1 : print_tree(root); break;
    default : printf("warning: delete function does not work well.\n"); break;
    }
  }

  free_tree(root);
  return 0;
}
