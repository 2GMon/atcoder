#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  
  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  ll medX = X[N / 2];
  ll medY = Y[N / 2];
  
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += abs(X[i] - medX) + abs(Y[i] - medY);
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