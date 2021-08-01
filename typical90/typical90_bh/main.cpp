#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int INF = 1000000;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> dpL(N, INF), dpR(N, INF);
  vector<int> L(N, 0), R(N, 0);
  for (int i = 0; i < N; i++) {
    int idx = lower_bound(dpL.begin(), dpL.end(), A[i]) - dpL.begin();
    dpL[idx] = A[i];
    L[i] = lower_bound(dpL.begin(), dpL.end(), INF) - dpL.begin();
  }
  for (int i = 0; i < N; i++) {
    int idx = lower_bound(dpR.begin(), dpR.end(), A[N - 1 - i]) - dpR.begin();
    dpR[idx] = A[N - 1 - i];
    R[N - 1 - i] = lower_bound(dpR.begin(), dpR.end(), INF) - dpR.begin();
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, L[i] + R[i] - 1);
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