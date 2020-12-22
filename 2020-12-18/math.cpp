#include <cstdio>
#include <vector>
#include <cctype>
using namespace std;

typedef long long int num;

struct node_t {
  node_t* parent;
  vector<node_t*> children;
  char c;
  num value() {
    if (isdigit(c)) {
      return c-'0';
    }
    if (c=='(') {
      int n = children.size();
      num total = children[0]->value();
      for(int i=1; i<n; i+=2) {
	if (children[i]->c == '+') {
	  total += children[i+1]->value();
	}
	else {
	  total *= children[i+1]->value();
	}
      }
      return total;
    }
    return 0;
  }
  void clear() {
    for(auto i : children) {
      i->clear();
      delete i;
    }
  }
  void debug(int level) {
    ++level;
    printf("%*c\n", 2*level, c);
    if (c=='(') {
      for(auto i : children) {
	i->debug(level);
      }
    }
  }
};

char buffer[1024];

node_t* parse() {
  node_t* root = new node_t;
  root->c='(';
  node_t* current = root;
  for(int i=0; buffer[i]!='\n'; ++i) {
    if (buffer[i]==' ') {
      continue;
    }
    if (buffer[i]==')') {
      current = current->parent;
      continue;
    }
    node_t* a = new node_t;
    a->c = buffer[i];
    a->parent = current;
    current->children.push_back(a);
    if (buffer[i]=='(') {
      current = a;
    }
  }
  if (root != current)
    printf("deu merda!\n");
  return root;
}

int main() {
  num total;
  node_t * tree;
  while(fgets(buffer, 1023, stdin)) {
    tree = parse();
    num x = tree->value();
    total+=x;
    printf("%lld %lld\n", x, total);
    tree->clear();
    delete tree;
  }
  printf("%lld\n", total);
  return 0;
}
