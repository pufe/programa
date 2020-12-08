#include <cstdio>
#include <cstring>

char buffer[1024];

int main() {
  int n;
  scanf(" %d", &n);
  fgets(buffer, 1023, stdin);
  for(int i=0; i<n; ++i) {
    fgets(buffer, 1023, stdin);
    int size=strlen(buffer);
    buffer[size-1]=0;
    --size;
    for(int j=0; j<size; ++j) {
      if ((buffer[j]>='a'&&buffer[j]<='z')||
	  (buffer[j]>='A'&&buffer[j]<='Z'))
	buffer[j]+=3;
    }
    for(int j=0; j<(size+1)/2; ++j) {
      buffer[j]--;
    }
    for(int j=size-1; j>=0; --j)
      printf("%c", buffer[j]);
    printf("\n");
  }
  return 0;
}
