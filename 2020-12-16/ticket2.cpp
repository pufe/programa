#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct interval_t {
  int lb, ub;
  bool contains(int v) {
    return v<=ub && v>=lb;
  }
};

struct field_t {
  string name;
  interval_t a, b;
  bool validates(int v) {
    return a.contains(v) || b.contains(v);
  }
};

char buffer[1024];
char field_name[64];

bool mtx[32][32];
int position[32];
bool taken[32];

vector<int> parse_ticket() {
  int p=0;
  int delta;
  int x;
  vector<int> r;
  while(buffer[p]!='\n') {
    sscanf(buffer+p, "%d%n", &x, &delta);
    r.push_back(x);
    p+=delta;
    if (buffer[p]==',')
      ++p;
  }
  return r;
}

bool find_permutation(int p, int n) {
  if (p==n)
    return true;
  for(int i=0; i<n; ++i) {
    if (!taken[i] && mtx[i][p]) {
      position[p] = i;
      taken[i]=true;
      if (find_permutation(p+1, n))
	return true;
      taken[i]=false;
    }
  }
  return false;
}

int main() {
  vector<field_t> fields;
  interval_t a, b;
  while (true) {
    fgets(buffer, 1023, stdin);
    if (buffer[0]=='\n')
      break;
    // field name: n-n or n-n
    sscanf(buffer, "%[^:]: %d-%d or %d-%d",
	   field_name, &a.lb, &a.ub, &b.lb, &b.ub);
    fields.push_back(field_t{string(field_name), a, b});
  }
  fgets(buffer, 1023, stdin); // your ticket
  fgets(buffer, 1023, stdin);
  vector<int> my_ticket = parse_ticket();
  vector<int> nearby_ticket;
  fgets(buffer, 1023, stdin); // empty line
  fgets(buffer, 1023, stdin); // nearby tickets:
  
  int n = fields.size();

  for(int i=0; i<n; ++i) {
    taken[i]=false;
    for(int j=0; j<n; ++j)
      mtx[i][j]=true;
  }

  while(fgets(buffer, 1023, stdin)) {
    nearby_ticket = parse_ticket();
    bool is_valid = true;
    for(auto value : nearby_ticket) {
      bool ok = false;
      for(auto field : fields) {
	if (field.validates(value))
	  ok = true;
      }
      if (!ok) {
	is_valid = false;
      }
    }
    if (is_valid) {
      for(int i=0; i<n; ++i)
	for(int j=0; j<n; ++j)
	  if (!fields[j].validates(nearby_ticket[i]))
	    mtx[i][j]=false;
    }
  }
  find_permutation(0, n);
  long long int p=1;
  for(int i=0; i<6; ++i) {
    printf("ticket[%d] = %d\n", position[i],
	   my_ticket[position[i]]);
    p*=my_ticket[position[i]];
  }
  printf("%lld\n", p);
  return 0;
}
