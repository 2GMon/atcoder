#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  ll N;
  cin >> N;

  ll ans = 0;
  for (ll i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      ans += i + (N / i);
      if (i == N / i) ans -= i;
    }
  }
  if (ans == N * 2) cout << "Perfect" << endl;
  else if (ans < N * 2) cout << "Deficient" << endl;
  else if (N * 2 < ans) cout << "Abundant" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}