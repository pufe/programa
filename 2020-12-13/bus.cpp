#include <cstdio>
#include <cstring>
#include <regex>
#include <string>
using namespace std;

char buffer[1024];

int main() {
  int n;
  int size;
  fgets(buffer, 1023, stdin);
  sscanf(buffer, "%d", &n);
  fgets(buffer, 1023, stdin);
  size = strlen(buffer);
  regex re("[0-9]+", regex_constants::extended);
  auto numbers_begin = cregex_iterator(buffer, buffer+size, re);
  auto numbers_end = cregex_iterator();

  int best_bus = 0;
  int min_time = 1000000;

  for(auto i = numbers_begin; i!= numbers_end; ++i) {
    int x;
    sscanf(i->str().c_str(), "%d", &x);
    int t = x - (n%x);
    if (t < min_time) {
      min_time = t;
      best_bus = x;
    }
  }
  printf("%d * %d = %d\n", min_time, best_bus, min_time*best_bus); 
  return 0;
}
