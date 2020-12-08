#include <cstdio>
#include <algorithm> // sort
using namespace std;
const int maxn = 110;
struct process_t {
  int start, end, duration, arrival;
  bool operator<(const process_t other) const {
    return arrival < other.arrival;
  }
};
process_t process[maxn];
int main() {
  int n;
  int tmt = 0, tme = 0;
  int free_at=0;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d %d", 
	  &process[i].arrival,
	  &process[i].duration);
  }
  sort(process, process+n);
  for(int i=0; i<n; ++i) {
    if (free_at < process[i].arrival) {
      process[i].start = process[i].arrival;
      process[i].end = process[i].start + process[i].duration;
      free_at = process[i].end;
    } else {
      process[i].start = free_at;
      process[i].end = process[i].start + process[i].duration;
      free_at = process[i].end;
    }
  }
  for(int i=0; i<n; ++i) {
    tme += process[i].start - process[i].arrival;
    tmt += process[i].end - process[i].arrival;
  }
  printf("TME:%.1lf\n", double(tme)/n);
  printf("TMT:%.1lf\n", double(tmt)/n);
  return 0;
}
