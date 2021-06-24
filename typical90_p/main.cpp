#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)


void Main() {
  ll N;
  cin >> N;
  ll A, B, C;
  cin >> A >> B >> C;

  ll ans = 10000;
  for (int a = 0; a <= 9999; a++) {
    for (int b = 0; b <= 9999; b++) {
      ll nokori = N - A * a - B * b;
      if (nokori >= 0 && nokori % C == 0) ans = min(ans, a + b + nokori / C);
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