#include <stdio.h>

struct node {
    int key;
    struct node *parent, *left, *right;
};

print_tree(pp)
    struct node *pp;
{
    ptree(pp, 0);
}

ptree(p, h)
    struct node *p;
    int h;
{
    int i;
    if (p != NULL) {
        ptree(p->right, h+1);
        for (i=1; i<=h; i++) printf("    ");
        printf("%4d\n", p->key);
        ptree(p->left, h+1);
    }
}