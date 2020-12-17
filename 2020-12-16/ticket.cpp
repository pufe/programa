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

int main() {
  int error_rate=0;
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
  int c=0;
  while(fgets(buffer, 1023, stdin)) {
    nearby_ticket = parse_ticket();
    for(auto value : nearby_ticket) {
      bool ok = false;
      for(auto field : fields) {
	if (field.validates(value))
	  ok = true;
      }
      if (!ok) {
	printf(" [%d]", value);
	error_rate += value;
      }
      else {
	printf(" %d", value);
      }
    }
    printf("\n");
    ++c;
  }
  printf("%d\n", c);
  printf("%d\n", error_rate);
  return 0;
}
