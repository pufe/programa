#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int, int> > findPath(vector<vector<bool> >& visited, 
				 int i, int n, int m) {
  int x = i;
  int y = i;
  vector<pair<int, int> > path;
  path.push_back(make_pair(i, i));
  for(int k=0; k<4; ++k) {
    while(true) {
      x += dx[k];
      y += dy[k];
      if (x >= n || x < 0 || y >=m || y < 0) {
	x -= dx[k];
	y -= dy[k];
	break;
      }
      if (visited[x][y]) {
	x -= dx[k];
	y -= dy[k];
	break;
      }
      path.push_back(make_pair(x, y));
      visited[x][y] = true;
    }
  }
  return path;
}

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int> > matrix, int r) {
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<bool> > visited(n);
  vector<vector<int> > answer(n);

  for(int i=0; i<n; ++i) {
    visited[i].resize(m);
    answer[i].resize(m);
  }

  for(int i=0; i<n; ++i) {
    if (!visited[i][i]) {
      vector<pair<int, int> > &path = findPath(visited, i, n, m);
      int p_size = path.size();
      for(int j=0; j<p_size; ++j) {
	int x = path[j].first;
	int y = path[j].second;
	int nx = path[(j+r)%p_size].first;
	int ny = path[(j+r)%p_size].second;
	answer[nx][ny]=matrix[x][y];
      }
    }
    else {
      break;
    }
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      if (j>0)
	printf(" ");
      printf("%d", answer[i][j]);
    }
    printf("\n");
  }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int> > matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
