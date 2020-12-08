#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

vector<string> all_str;
char str[13];
void generate(int digits, int signs, bool needs_digit) {
  if (digits == 9) {
    str[13] = 0;
    all_str.push_back(string(str));
    return;
  }
  int remaining_digits = 9 - digits;
  int remaining_signs = 3 - signs;
  if (remaining_digits > remaining_signs) {
    str[digits+signs] = '1' + digits;
    generate(digits+1, signs, false);
  }
  if (not needs_digit and remaining_signs > 0) {
    str[digits+signs] = '-';
    generate(digits, signs+1, true);
    str[digits+signs] = '+';
    generate(digits, signs+1, true);
  }
}
int calculate(string s) {
  int total=0;
  int current=0;
  int sign = 1;
  for(unsigned i=0; i<s.size(); ++i) {
    if (s[i] == '-') {
      total += sign * current;
      current = 0;
      sign = -1;
    } else if (s[i] == '+') {
      total += sign * current;
      current = 0;
      sign = 1;
    } else {
      current = 10*current + s[i]-'0';
    }
  }
  total += sign*current;
  return total;
}
int main() {
  map<int, string> m;
  generate(0,0,true);
  sort(all_str.begin(), all_str.end());
  for(auto&& str : all_str) {
    m[calculate(str)] = str;
  }
  int n;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    int x;
    scanf(" %d", &x);
    printf("%s = %d\n", m[x].c_str(), x);
  }
  return 0;
}
