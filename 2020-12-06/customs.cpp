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

void add_to_group(group_t *g) {
  for(int i=0; buffer[i]!='\n'; ++i) {
    g->s.insert(buffer[i]);
  }
}

bool read_group(group_t *g) {
  int n=0;
  g->s.clear();
  while(read_line()) {
    ++n;
    add_to_group(g);
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
