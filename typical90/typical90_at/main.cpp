#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int MOD = 46;

void Main() {
  int N;
  cin >> N;

  map<int, ll> A, B, C;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a % MOD]++;
  }
  for (int i = 0; i < N; i++) {
    int b;
    cin >> b;
    B[b % MOD]++;
  }
  for (int i = 0; i < N; i++) {
    int c;
    cin >> c;
    C[c % MOD]++;
  }

  ll ans = 0;
  for (int i = 0; i < MOD; i++) {
    for (int j = 0; j < MOD; j++) {
      for (int k = 0; k < MOD; k++) {
        if((i + j + k) % MOD == 0) ans += A[i] * B[j] * C[k];
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