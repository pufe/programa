#include <cstdio>

struct node_t {
  int value;
  node_t *left, *right;
};

node_t* new_node(int value) {
  node_t* p = new node_t;
  p->value = value;
  p->right = NULL;
  p->left = NULL;
  return p;
}

void insert_tree(node_t ** tree, int x) {
  if (*tree == NULL) {
    *tree = new_node(x);
  } else if ((*tree)->value < x) {
    insert_tree(&((*tree)->right), x);
  } else {
    insert_tree(&((*tree)->left), x);    
  }
}

void print_tree(node_t * tree, int kind) {
  if (tree == NULL)
    return;
  if (kind == 0)
    printf(" %d", tree->value);
  print_tree(tree->left, kind);
  if (kind == 1)
    printf(" %d", tree->value);
  print_tree(tree->right, kind);
  if (kind == 2)
    printf(" %d", tree->value);
}

void clear_tree(node_t ** tree) {
  if (*tree == NULL)
    return;
  clear_tree(&((*tree)->left));
  clear_tree(&((*tree)->right));
  delete *tree;
  *tree = NULL;
}

int main() {
  int num_tests;
  int n, x;
  node_t *tree = NULL;
  scanf(" %d", &num_tests);
  for(int test=1; test<=num_tests; ++test) {
    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      scanf(" %d", &x);
      insert_tree(&tree, x);
    }
    printf("Case %d:\n", test);
    printf("Pre.:");
    print_tree(tree, 0);
    printf("\n");
    printf("In..:");
    print_tree(tree, 1);
    printf("\n");
    printf("Post:");
    print_tree(tree, 2);
    printf("\n\n");
    clear_tree(&tree);    
  }
  return 0;
}
