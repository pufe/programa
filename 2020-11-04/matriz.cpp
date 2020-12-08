#include <cstdio>
#include <stack>
#include <utility> //pair
#include <algorithm> //max
using namespace std;

const int maxn=1024;

int mtx[maxn][maxn];
int sub_mtx[maxn][maxn];

int is_cool(int i, int j) {
  if (mtx[i][j]+mtx[i+1][j+1] <= mtx[i+1][j]+mtx[i][j+1])
    return 1;
  else
    return 0;
}

int main() {
  int n, m;
  int best = 0;
  stack<pair<int, int> > st;
  scanf(" %d %d", &n, &m);
  best = max(n, m);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      scanf(" %d", &mtx[i][j]);
    }
  }
  for(int i=0; i<n-1; ++i) {
    for(int j=0; j<m-1; ++j) {
      sub_mtx[i][j] = is_cool(i, j);
      if (sub_mtx[i][j]==1 && j>0)
	sub_mtx[i][j] += sub_mtx[i][j-1];
    }
  }
  /*for(int i=0; i<n-1; ++i) {
    for(int j=0; j<m-1; ++j)
      printf(" %d", sub_mtx[i][j]);
    printf("\n");
  }
  printf("\n");*/
  for(int j=0; j<m-1; ++j) {
    for(int i=0; i<n-1; ++i) {
      int start = i;
      while(!st.empty() && st.top().first > sub_mtx[i][j]) {
	start = st.top().second;
	int height = i - st.top().second;
	int width = st.top().first;
	int area = (height+1)*(width+1);
	if (area > best)
	  best = area;
	st.pop();
      }
      if (st.empty() || st.top().first < sub_mtx[i][j]) {
	st.push(make_pair(sub_mtx[i][j], start));
      }
    }
    while(!st.empty()) {
      int height = n - 1 - st.top().second;
      int width = st.top().first;
      int area = (height+1)*(width+1);
      if (area > best)
	best = area;
      st.pop();
    }
  }
  printf("%d\n", best);
  return 0;
}
