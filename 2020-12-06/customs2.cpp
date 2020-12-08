#include <cstdio>
#include <set>
using namespace std;

struct group_t {
  set<char> s;
};

char buffer[1024];

bool read_line() {
  if (!fgets(buffer, 1023, stdin))
    return false;
  if (buffer[0]=='\n')
    return false;
  return true;
}

set<char> intersection(set<char> a, set<char> b) {
  auto it_a = a.begin();
  auto it_b = b.begin();
  set<char> r;
  while(it_a != a.end() && it_b != b.end()) {
    if (*it_a < *it_b)
      ++it_a;
    else if (*it_b < *it_a)
      ++it_b;
    else {
      r.insert(*it_a);
      ++it_a;
      ++it_b;
    }
  }
  return r;
}

void add_to_group(group_t *g, int n) {
  set<char> s;
  for(int i=0; buffer[i]!='\n'; ++i) {
    s.insert(buffer[i]);
  }
  if (n==1) {
    g->s = s;
  }
  else {
    g->s = intersection(s, g->s);
  }
}

bool read_group(group_t *g) {
  int n=0;
  g->s.clear();
  while(read_line()) {
    ++n;
    add_to_group(g, n);
  }
  return n>0;
}

int main() {
  int total=0;
  group_t g;
  while(read_group(&g)) {
    total += g.s.size();
  }
  printf("%d\n", total);
  return 0;
}
