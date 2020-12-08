#include <cstdio>
#include <cstring>

int main() {
  int n, lines_per_page, chars_per_line;
  char word[124];
  while(true) {
    if (scanf(" %d %d %d", &n,
	      &lines_per_page,
	      &chars_per_line)!=3)
      break;
    ++chars_per_line;
    int current_page = 1;
    int current_line = 1;
    int current_char = 0;
    for(int i=0; i<n; ++i) {
      scanf(" %s", word);
      int length = strlen(word)+1;
      if (current_char + length > chars_per_line) {
	current_char = 0;
	++current_line;
	if (current_line > lines_per_page) {
	  current_line=1;
	  ++current_page;
	}
      }
      current_char += length;
    }
    printf("%d\n", current_page);
  }
  return 0; 
}
