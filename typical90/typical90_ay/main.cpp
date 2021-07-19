#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  ll P;
  cin >> N >> K >> P;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<vector<ll>> a(N + 1), b(N + 1);
  for (int i = 0; i < (1 << (N / 2 + 1)); i++) {
    int cnt = 0;
    ll sum = 0;
    for (int j = 0; (1 << j) < (1 << (N / 2 + 1)); j++) {
      if (i & (1 << j)) {
        cnt++;
        sum += A[j];
      }
    }
    a[cnt].push_back(sum);
  }
  for (int i = 0; i < (1 << (N - N / 2 - 1)); i++) {
    int cnt = 0;
    ll sum = 0;
    for (int j = 0; (1 << j) < (1 << (N - N /2 - 1)); j++) {
      if (i & (1 << j)) {
        cnt++;
        sum += A[N / 2 + 1 + j];
      }
    }
    b[cnt].push_back(sum);
  }
  for (int i = 0; i <= N; i++) {
    sort(a[i].begin(), a[i].end());
    sort(b[i].begin(), b[i].end());
  }

  ll ans = 0;
  for (int i = 0; i <= N; i++) {
    int k = K - i;
    for (ll p : a[i]) {
      int num = lower_bound(b[k].begin(), b[k].end(), P - p + 1) - b[k].begin();
      ans += num;
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