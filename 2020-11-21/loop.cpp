#include <cstdio>

const int maxn = 10010;
int pcm[maxn];

int main() {
  while(true) {
    int n, c=0;
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=0; i<n; ++i)
      scanf(" %d", &pcm[i]);
    for(int i=0; i<n; ++i) {
      if (pcm[i] > pcm[(i+1)%n] && pcm[i] > pcm[(i+n-1)%n])
	++c;
      else if (pcm[i] < pcm[(i+1)%n] && pcm[i] < pcm[(i+n-1)%n])
	++c;
    }
    printf("%d\n", c);
  }
  return 0;
}
