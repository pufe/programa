#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

struct bignum {
  vector<int> d;
  void set(int v) {
    d.resize(1);
    d[0] = v;
  }
  void multiply(int v) {
    int carry = 0;
    for(unsigned int i=0; i<d.size(); ++i) {
      d[i]*=v;
      d[i]+=carry;
      carry = d[i]/1000;
      d[i]%=1000;
    }
    if (carry > 0) {
      d.push_back(carry);
    }
  }
  void print() {
    for(int i=d.size()-1; i>=0; --i) {
      if (i==(int)d.size()-1)
	printf("%d", d[i]);
      else
	printf("%03d", d[i]);
    }
    printf("\n");
  }
};

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
  bignum r;
  r.set(1);
  for(int i=2; i<=n; ++i)
    r.multiply(i);
  r.print();
}

int main()
{
    int n;
    cin >> n;

    extraLongFactorials(n);

    return 0;
}
