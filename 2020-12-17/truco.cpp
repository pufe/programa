#include <cstdio>
#include <set>
using namespace std;

char deck[1024];

bool contains_all(set<char> &s, const char *str) {
  for(int i=0; str[i]; ++i)
    if (s.count(str[i])==0)
      return false;
  return true;
}

int main() {
  int t;
  set<char> s;
  for(scanf(" %d", &t); t>0; --t) {
    scanf(" %s", deck);
    for(int i=0; deck[i]; ++i)
      s.insert(deck[i]);
    if (contains_all(s, "AJQK"))
      printf("Aaah muleke\n");
    else
      printf("Ooo raca viu\n");
    s.clear();
  }
  return 0;
}
