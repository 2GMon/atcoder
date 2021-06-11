#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  cin >> N >> K;

  ll ans = 0;
  ll num = 0;
  for (int i = 1; i <= N; i++) {
    if (i % K == 0) num++;
  }
  ans = num * num * num;

  if (K % 2 == 0) {
    num = 0;
    for (int i = 1; i <= N; i++) {
      if (i % K == K / 2) num++;
    }
    ans += num * num * num;
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