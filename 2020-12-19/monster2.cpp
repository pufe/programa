#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

struct rule_t {
  char c;
  bool is_simple;
  vector<vector<int> > options;
  
  void debug(int n) {
    printf("%d:", n);
    if (is_simple) {
      printf(" \"%c\"\n", c);
    } else {
      for(auto op : options) {
	printf(" |");
	for(auto i : op) {
	  printf(" %d", i);
	}
      }
      printf("\n");
    }
  }
};

char buffer[1024];
map<int, rule_t*> grammar;
map<tuple<int, int, int>, bool> memo;

void add_rule() {
  int pos=0;
  int delta;
  int rule_number;
  rule_t *r = new rule_t;
  sscanf(buffer+pos, " %d: %n", &rule_number, &delta);
  grammar[rule_number] = r;
  pos+=delta;
  if (buffer[pos]=='"') {
    r->is_simple = true;
    r->c = buffer[pos+1];
    return;
  }
  r->is_simple = false;
  r->options.push_back(vector<int>{});
  int n=0;
  while(buffer[pos]!='\0') {
    int x;
    if (sscanf(buffer+pos, " %d %n", &x, &delta)!=1) {
      ++pos;
      r->options.push_back(vector<int>{});
      ++n;
    }
    else {
      pos+=delta;
      r->options[n].push_back(x);
    }
  }
}

bool match(int, int, int);
bool match_option(int start, int end, vector<int> op) {
  if (op.size()==1)
    return match(start, end, op[0]);
  if (op.size()==2) {
    for(int i=start+1; i<end; ++i) {
      if (match(start, i, op[0]) &&
	  match(i, end, op[1]))
	return true;
    }
    return false;
  }
  for(int i=start+1; i<end; ++i) {
    for(int j=i+1; j<end; ++j) {
      if (match(start, i, op[0]) &&
	  match(i, j, op[1]) &&
	  match(j, end, op[2]))
	return true;
    }
  }
  return false;
}

bool match(int start, int end, int rule) {
  tuple<int, int, int> state(start, end, rule);
  auto it = memo.find(state);
  if (it!=memo.end())
    return it->second;
  rule_t * r = grammar[rule];

  if (r->is_simple) {
    return end == start+1 && buffer[start]==r->c;
  }
  for(auto op : r->options) {
    if (match_option(start, end, op)) {
      memo.insert(make_pair(state, true));
      return true;
    }
  }
  memo.insert(make_pair(state, false));
  return false;
}

int main() {
  int total=0;
  int len;
  while(true) {
    fgets(buffer, 1023, stdin);
    if (buffer[0]=='\n')
      break;
    add_rule();
  }
  for(auto it : grammar) {
    it.second->debug(it.first);
  }
  while(scanf(" %s", buffer)==1) {
    len = strlen(buffer);
    memo.clear();
    if (match(0, len, 0)) {
      printf("sim, ");
      ++total;
    }
    printf("foi\n");
  }
  printf("%d\n", total);
  return 0;
}
