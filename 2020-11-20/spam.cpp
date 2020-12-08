#include <cstdio>
#include <vector>
using namespace std;

const int NOT_FILLED = 4;
typedef char name_t[32];

struct spam_t {
  int lower, upper;
  name_t attribute[3];
  int get_index(int x) {
    if (x<lower)
      return 0;
    if (x>=upper)
      return 2;
    return 1;
  }
};

spam_t spam[110];

struct person_t {
  name_t name;
  int attribute[110];
  vector<int> adj;
};
person_t person[32];

void dfs(int starter, int index) {
  int messages = person[starter].adj.size();
  int attribute = spam[index].get_index(messages);
  person[starter].attribute[index] = attribute;
  for(int j : person[starter].adj) {
    if (person[j].attribute[index] == NOT_FILLED)
      dfs(j, index);
  }
}

int main() {
  while(true) {
    int n, m=0;
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=1; i<=n; ++i) {
      person[i].adj.clear();
      while(true) {
	int x;
	scanf(" %d", &x);
	if (x==0)
	  break;
	person[i].adj.push_back(x);
      }
    }
    while(true) {
      int starter;
      scanf(" %d", &starter);
      if (starter == 0)
	break;
      scanf(" %d %d", &spam[m].lower, &spam[m].upper);
      for(int i=0; i<3; ++i)
	scanf(" %s", spam[m].attribute[i]);
      for(int i=1; i<=n; ++i)
	person[i].attribute[m] = NOT_FILLED;
      dfs(starter, m);
      for(int i=1; i<=n; ++i)
	if (person[i].attribute[m] == NOT_FILLED)
	  person[i].attribute[m] = spam[m].get_index(0);
      ++m;
    }
    for(int i=1; i<=n; ++i) {
      scanf(" %s", person[i].name);
      printf("%s: ", person[i].name);
      for(int j=0; j<m; ++j) {
	printf("%s ", spam[j].attribute[person[i].attribute[j]]);
      }
      printf("\n");
    }
  }
  return 0;
}
