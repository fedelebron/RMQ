#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vint;

int ceil_log2(int x) {
  return 32 - __builtin_clz(x);
}

struct RMQ {
  vint& v;
  vector<vint> A;
  RMQ(vint& v) : v(v), A(v.size(), vint(ceil_log2(v.size()) + 1, 0)) {
    int n = v.size();
    int i, j, k;
    for (i = 0; i < n; ++i) {
      A[i][0] = i;
    }
    j = 1;
    k = 1;
    do {
      for (i = 0; i < n; ++i) {
        if (i + k >= n) break;
        if (v[A[i][j - 1]] < v[A[i + k][j - 1]]) {
          A[i][j] = A[i][j - 1];
        } else {
          A[i][j] = A[i + k][j - 1];
        }
      }
      k <<= 1;
      ++j;
    } while(k < n);
  }

  int rmq(int i, int j) {
    int k = ceil_log2(j - i + 1) - 1;
    if (v[A[i][k]] < v[A[j - (1 << k) + 1][k]]) {
      return A[i][k];
    } else {
      return A[j - (1 << k) + 1][k];
    }
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