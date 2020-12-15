#include <cstdio>
#include <map>
#include <cstdint>
using namespace std;

typedef int64_t num;
char buffer[1024];

void update_mask(num &set_mask, num &float_mask) {
  set_mask = 0;
  float_mask = 0;
  for(int i=7; buffer[i]!='\n'; ++i) {
    set_mask <<= 1;
    float_mask <<= 1;
    if (buffer[i]=='X')
      float_mask|=1;
    if (buffer[i]=='1')
      set_mask|=1;
  }
}
void set_all_combinations(map<num, num> &m, 
			  num pos, num mask, num val) {
  if (mask != 0) {
    num bit = mask&-mask;
    set_all_combinations(m, pos|bit, mask^bit, val);
    set_all_combinations(m, pos&~bit, mask^bit, val);
  } else {
    m[pos] = val;
  }
}
void set_memory(map<num, num> &m, num set_mask, num float_mask) {
  num pos, val;
  sscanf(buffer, "mem[%ld] = %ld", &pos, &val);
  pos |= set_mask;
  set_all_combinations(m, pos, float_mask, val);
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
  num float_mask=0;
  while(fgets(buffer, 1023, stdin)) {
    if (buffer[1]=='a') {
      update_mask(set_mask, float_mask);
    }
    else {
      set_memory(m, set_mask, float_mask);
    }
  }
  printf("%ld\n", sum_values(m));
  return 0;
}
