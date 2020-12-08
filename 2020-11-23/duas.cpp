#include <cstdio>

char str[32];
int freq[10];

int main() {
  int first_problem = -1;
  scanf(" %s", str);
  for(int i=0; str[i]; ++i) {
    ++freq[str[i]-'0'];
    if (freq[str[i]-'0'] > 2) {
      first_problem = i;
      break;
    }
  }
  if (first_problem >=0) {
    int i = first_problem;
    while(true) {
      if (str[i] == '0') {
	freq[0]--;
	--i;
      } else {
	freq[str[i]-'0']--;
	str[i]--;
	freq[str[i]-'0']++;
	if (freq[str[i]-'0'] <= 2)
	  break;
      }
    }
    first_problem = i;
    int current_digit = 9;
    for(int i=first_problem+1; str[i]; ++i) {
      while(freq[current_digit]>=2)
	--current_digit;
      str[i]=current_digit+'0';
      freq[current_digit]++;
    }
  }
  char* ptr = str;
  while(*ptr=='0')
    ++ptr;
  printf("%s\n", ptr);
  return 0;
}
