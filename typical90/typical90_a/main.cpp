#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, L, K;
  cin >> N >> L >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int lb = -1, ub = L + 1;
  while (ub - lb > 1) {
    int c = (ub + lb) / 2;

    int left = 0;
    int num = 0;
    rep(i, N) {
      if (A[i] - left >= c && L - A[i] >= c) {
        num++;
        left = A[i];
      }
    }

    // 答えはc以上
    if (num >= K) lb = c;
    else ub = c;
  }

  cout << lb << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}