#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vint;

struct RMQ {
  vector<vint> A;

  RMQ(vint& v) : A(v.size(), vint(v.size(), 0)) {
    int n = v.size();
    int i, j;
    for (i = 0; i < n; ++i) {
      A[i][i] = i;
      for (j = i + 1; j < n; ++j) {
        if (v[j] < v[A[i][j - 1]]) {
          A[i][j] = j;
        } else {
          A[i][j] = A[i][j - 1];
        }
      }
    }
  }

  int rmq(int i, int j) {
    if (j < i) swap(i, j);
    return A[i][j];        
  }
};

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    int i, j;
    for (i = 0; i < n; ++i) {
      cin >> v[i];
    }

    RMQ solver(v);

    int m;
    cin >> m;
    int k;
    for (k = 0; k < m; ++k) {
      cin >> i >> j;
      cout << solver.rmq(i, j) << endl;
    }
  }
}
