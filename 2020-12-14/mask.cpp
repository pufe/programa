#include <cstdio>
#include <map>
#include <cstdint>
using namespace std;

typedef int64_t num;
char buffer[1024];

void update_mask(num &set_mask, num &reset_mask) {
  set_mask = 0;
  reset_mask = 0;
  for(int i=7; buffer[i]!='\n'; ++i) {
    set_mask <<= 1;
    reset_mask <<= 1;
    if (buffer[i]=='0')
      reset_mask|=1;
    if (buffer[i]=='1')
      set_mask|=1;
  }
}
void set_memory(map<num, num> &m, num set_mask, num reset_mask) {
  num pos, val;
  sscanf(buffer, "mem[%ld] = %ld", &pos, &val);
  val |= set_mask;
  val &= ~reset_mask;
  m[pos] = val;
}
num sum_values(map<num, num> &m) {
  num total = 0;
  for(auto i : m) {
    total += i.second;
  }
  return total;
}

int main() {
  map<num, num> m;
  num set_mask=0;
  num reset_mask=0;
  while(fgets(buffer, 1023, stdin)) {
    if (buffer[1]=='a') {
      update_mask(set_mask, reset_mask);
    }
    else {
      set_memory(m, set_mask, reset_mask);
    }
  }
  printf("%ld\n", sum_values(m));
  return 0;
}
