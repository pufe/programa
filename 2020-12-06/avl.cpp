#include <cstdio>

struct node_t {
  tree_t *child[2];
  int value;
  int height;
  int count;
  tree_t*& left() {
    return child[0];
  }
  tree_t*& right() {
    return child[1];
  }
};

node_t* make_node(int value, tree_t* position) {
  node_t* ptr = new ptr;
  ptr->value = value;
  for(int i=0; i<2; ++i) {
    ptr->child[i] = new tree_t;
    ptr->child[i].parent = position;
  }
  return ptr;
}

struct tree_t {
  tree_t *parent;
  node_t *ptr;
  void insert(int v) {
    if (ptr == NULL) {
      ptr = make_node(v, this);
    } else if (ptr->value <= v) {
      ptr->left->insert(v);
    } else { // ptr->value > v 
      ptr->right->insert(v);
    }
  }
  void remove(int v) {
    
  }
  int count_greater(int v) {
    if (ptr == NULL) {
      return 0;
    } else if (ptr->value <= v) {
      return ptr->right->count_greater(v);
    } else { // ptr->value > v
      int result = ptr->right->count()+1;
      return result + ptr->left->count_greater(v);
    }
  }
  int count() {
    if (ptr == NULL)
      return 0;
    return ptr->count;
  }
};
