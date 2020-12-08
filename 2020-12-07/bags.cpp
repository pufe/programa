#include <cstdio>
#include <cstring>
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

node_t* find_or_create(map<string, node_t*>& dict, string name) {
  if (dict.find(name)==dict.end()) {
    node_t* x = new node_t;
    x->visited = false;
    dict[name] = x;
  }
  return dict[name];
}

int search(node_t* x) {
  int total=1;
  x->visited = true;
  for(auto i : x->adj_r) {
    if (!i->visited) {
      total += search(i);
    }
  }
  return total;
}

int main() {
  map<string, node_t*> dict;
  regex name_re("^[a-z]+ [a-z]+", regex_constants::extended);
  regex rel_re("([0-9]+) ([a-z]+ [a-z]+)",
	       regex_constants::extended);

  while(fgets(buffer, 1023, stdin)) {
    int buffer_size = strlen(buffer);
    cmatch name_m;
    regex_search(buffer, name_m, name_re);
    string name = name_m.str(0);
    node_t* x = find_or_create(dict, name);

    cregex_iterator rel_matches(buffer, buffer+buffer_size, rel_re);
    for(auto i = rel_matches; i!= cregex_iterator(); ++i) {
      node_t* y = find_or_create(dict, i->str(2));
      y->adj_r.push_back(x);
    }
  }

  printf("%d\n", search(dict["shiny gold"])-1);
  return 0;
}
