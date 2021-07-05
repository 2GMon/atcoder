#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  ll P;
  cin >> P;
  ll coin[11];
  coin[0] = 1;
  for (int i = 1; i <= 10; i++) {
    coin[i] = coin[i - 1] * i;
  }

  ll ans = 0;
  int i = 10;
  while (P != 0) {
    ans += P / coin[i];
    P %= coin[i];
    i--;
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