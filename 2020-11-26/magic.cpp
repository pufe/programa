#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int> > matrix;

matrix referenceMagicSquare() {
  return matrix {
    {8, 3, 4},
    {1, 5, 9},
    {6, 7, 2}
  };
}

int calculateCost(matrix a, matrix b) {
  int total = 0;
  for(int i=0; i<3; ++i)
    for(int j=0; j<3; ++j)
      total+=abs(a[i][j]-b[i][j]);
  return total;
}
matrix flip(matrix a) {
  matrix r(3);
  for(int i=0; i<3; ++i) {
    r[i].resize(3);
    for(int j=0; j<3; ++j) {
      r[i][j] = a[2-i][j];
    }
  }
  return r;
}
matrix rotate(matrix a) {
  matrix r(3);
  for(int i=0; i<3; ++i) {
    r[i].resize(3);
    for(int j=0; j<3; ++j) {
      r[i][j] = a[j][2-i];
    }
  }
  return r;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(matrix s) {
  matrix  magic = referenceMagicSquare();
  int cost = 1024;
  for(int i=0; i<4; ++i) {
    for(int j=0; j<2; ++j) {
      cost = min(cost, calculateCost(s, magic));
      magic = flip(magic);
    }
    magic = rotate(magic);
  }
  return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    matrix s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
