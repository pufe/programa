#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, set<string> > dict;
map<string, int> qt;

bool is_allergen_free(string a) {
  for(auto it : dict) {
    if (it.second.count(a)>0)
      return false;
  }
  return true;
}

set<string> intersect(set<string> a, set<string> b) {
  if (a.empty())
    return b;
  set<string> r;
  auto it_a = a.begin();
  auto it_b = b.begin();
  while(it_a!=a.end() && it_b!=b.end()) {
    if (*it_a == *it_b) {
      r.insert(*it_a);
      it_a++;
      it_b++;
    } else if (*it_a < *it_b) {
      it_a++;
    } else {
      it_b++;
    }
  }
  return r;
}

struct product_t {
  set<string> ingredients;
  vector<string> allergens;
};

product_t products[50];

int main() {
  int n=0;
  int len;
  char name[128];
  while(scanf(" %s", name)==1) {
    ++n;
    while(name[0]!='(') {
      string sname = string(name);
      qt[sname] = qt[sname]+1;
      products[n].ingredients.insert(sname);
      scanf(" %s", name);
    }
    scanf(" %s", name);
    len=strlen(name);
    while(name[len-1]!=')') {
      name[len-1]=0;
      string sname = string(name);
      products[n].allergens.push_back(sname);
      dict[sname]=intersect(dict[sname], products[n].ingredients);
      scanf(" %s", name);
      len=strlen(name);
    }
    name[len-1]=0;
    string sname = string(name);
    products[n].allergens.push_back(sname);
    dict[sname]=intersect(dict[sname], products[n].ingredients);
  }
  printf("qtt allergens: %lu\n", dict.size());
  for(auto it : dict) {
    printf("%s:", it.first.c_str());
    for(auto jt : it.second) {
      printf(" %s", jt.c_str());
    }
    printf("\n");
  }
  int total = 0;
  for(auto it : qt) {
    if (is_allergen_free(it.first))
      total+=it.second;
  }
  printf("%d\n", total);
  return 0;
}
