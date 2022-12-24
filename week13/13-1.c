#include<stdio.h>
#include<stdlib.h>
#define TRUE (1)

struct node {
  int key;
  struct node *parent, *left, *right;
};

struct node *new_node(int key) {
  struct node *p;

  p = (struct node *)malloc(sizeof(struct node));
  p->key = key;
  p->left = NULL;
  p->right = NULL;
  p->parent = NULL;

  return p;
}

int insert(int key, struct node *root) {

  //struct node *n;

  while (TRUE) {

    if (root->key == 0) {
      //n = new_node(key);
      //*root = *n;
      *root = *(new_node(key));
      root->left = new_node(0);
      root->right = new_node(0);
      return 1;
    }

    if (root->key > key)
      root = root->left;
    else if (root->key < key)
      root = root->right;
    else
      return 0;

  }

}

void free_tree(struct node *node) {
  if (node != NULL) {
    free_tree(node->left);
    free_tree(node->right);
    free(node);
  }
}

int main() {

  int key, det;
  struct node *root = new_node(0);

  while (TRUE) {
    printf("挿入するキーを入力してください: ");
    scanf("%d", &key);
    if (key <= 0)
      break;
    det = insert(key, root);
    switch (det) {
    case 0 : printf("%dはすでにノードに存在します.\n", key); break;
    case 1 : print_tree(root);
    }
  }

  free_tree(root);

  return 0;
}
