#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);

  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  ll ans = 0;
  rep(i, N) {
    ans += abs(A[i] - B[i]);
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