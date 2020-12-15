#include <cstdio>
#include <cstring>
#include <regex>
#include <string>
#include <utility>
using namespace std;

char buffer[1024];

typedef int64_t num;

pair<num, num> euclid(num a, num b) {
  num q;
  num c=1;
  num d=0;
  while(b>0) {
    q = a/b;
    num tmp = c-q*d;
    c = d;
    d = tmp;
    tmp = a%b;
    a = b;
    b = tmp;
  }
  return make_pair(a, c);
}
pair<num, num> crt(pair<num, num> A, pair<num, num> B) {
  num a = A.first;
  if (a==0)
    return B;
  num ra = A.second;
  num b = B.first;
  num rb = B.second;
  auto x = euclid(a, b);
  num gcd = x.first;
  num inv = x.second;
  inv = (inv%b+b)%b;
  num lcm = a*b / gcd;
  num dif = ((rb - ra)%b+b)%b;
  num f = (dif/gcd)*inv%b;
  return make_pair(lcm, f*a+ra);
}

int main() {
  int n;
  int size;
  pair<num, num> answer = make_pair(0,0);
  fgets(buffer, 1023, stdin);
  sscanf(buffer, "%d", &n);
  fgets(buffer, 1023, stdin);
  size = strlen(buffer);
  regex re("[0-9x]+", regex_constants::extended);
  auto numbers_begin = cregex_iterator(buffer, buffer+size, re);
  auto numbers_end = cregex_iterator();

  int count=0;
  for(auto i = numbers_begin; i!= numbers_end; ++i) {
    int a;
    int ra;
    if (i->str()[0] != 'x') {
      sscanf(i->str().c_str(), "%d", &a);
      ra = a - count;
      answer = crt(answer, make_pair(a, ra));
    }
    count++;
  }
  printf("%ld %ld\n", answer.first, answer.second);
  return 0;
}
