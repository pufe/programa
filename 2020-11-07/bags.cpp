#include <cstdio>
#include <string>
#include <regex>
#include <map>
#include <vector>
using namespace std;

struct node_t {
  vector<node_t*> adj_r;
  bool visited;
};

char buffer[1024];

int main() {
  map<string, node_t*> dict;
  while(fgets(buffer, 1023, stdin)) {
    regex name_re("^[a-z]+ [a-z]+", regex_constants::extended);
    string line(buffer);
    cmatch m;
    regex_search(buffer, m, name_re);
    string name = m.str(0);
    printf("'%s'\n", name.c_str());
  }
  return 0;
}
