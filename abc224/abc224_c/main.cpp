#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N;
  cin >> N;

  vector<ll> X(N), Y(N);
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        if ((Y[j] - Y[i]) * (X[k] - X[i]) != (Y[k] - Y[i]) * (X[j] - X[i])) ans++;
      }
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