#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int shift = 0;
  for (int i = 0; i < Q; i++) {
    int T, x, y;
    cin >> T >> x >> y;
    x--; y--;

    if (T == 1) {
      int X = x - shift;
      while (X < 0) X = N + X;
      int Y = y - shift;
      while (Y < 0) Y = N + Y;
      int tmp = A[X];
      A[X] = A[Y];
      A[Y] = tmp;
    } else if (T == 2) {
      shift++;
    } else {
      int X = x - shift;
      if (X < 0) X = N + X;
      cout << A[X] << endl;
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}