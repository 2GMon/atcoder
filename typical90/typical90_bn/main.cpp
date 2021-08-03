#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  vector<int> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i] >> R[i];
  }

  double ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int cond = 0, sum = 0;
      for (int k = R[i]; k >= L[i]; k--) {
        for (int l = R[j]; l >= L[j]; l--) {
          sum++;
          if (k > l) cond++;
        }
      }
      ans += (double)cond / (double)sum;
    }
  }

  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}