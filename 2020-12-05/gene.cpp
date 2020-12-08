#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct person_t {
  int family;
  vector<person_t*> adj;
};

person_t person[330];

int get_or_create(map<string, int>& dict, char name[]) {
  string str(name);
  if (dict.find(str)!=dict.end())
    return dict[str];
  int n = dict.size();
  person[n].family = 0;
  person[n].adj.clear();
  dict[str] = n;
  return n;
}

void dfs(person_t *p, int c) {
  p->family = c;
  for(auto it : p->adj)
    if (it->family==0)
      dfs(it, c);
}

int main() {
  int n, m;
  scanf(" %d %d", &m, &n);
  map<string, int> dict;
  for(int i=0; i<n; ++i) {
    char name1[64], rel[64], name2[64];
    scanf(" %s %s %s", name1, rel, name2);
    int p1 = get_or_create(dict, name1);
    int p2 = get_or_create(dict, name2);
    person[p1].adj.push_back(&person[p2]);
    person[p2].adj.push_back(&person[p1]);
  }
  int num_families=0;
  for(int i=0; i<m; ++i) {
    if (person[i].family==0) {
      ++num_families;
      dfs(&person[i], num_families);
    } 
  }
  printf("%d\n", num_families);
  return 0;
}
