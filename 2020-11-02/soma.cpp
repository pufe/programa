/*
aux -> 3 2 1 0 3 2 1
arr -> 0 0 0 k 0 0 0
         ^ ^ ^ ^ ^ ^
total = 16
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 500100;
int arr[maxn];
int zeroes[maxn];

int main() {
  int n, k;
  long long int rect=0;
  scanf(" %d %d", &n, &k);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &arr[i]);
  }
  int z=0;
  for(int i=n-1; i>=0; --i) {
    if (arr[i]==0) {
      ++z;
    }
    else {
      z=0;
    }
    zeroes[i]=z;
  }
  int start=0, end=0, sum=0; // cuidado com k=0
  while(true) { //ainda não sabemos condição de parada
    if (sum > k) {
      sum -= arr[start];
      start++;
    }
    else {
      if (sum == k) {
	rect += min(zeroes[start]+1, end-start);
      }
      if (end >= n)
	break;
      sum += arr[end];
      end++;
    }
  }
  printf("%lld\n", rect);
  return 0;
}
