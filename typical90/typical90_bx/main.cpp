#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  ll S = 0;
  vector<ll> A(N * 2);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    S += A[i];
    A[i + N] = A[i];
  }

  int r = 0;
  ll s = 0;
  bool yes = false;
  for (int l = 0; l < 2 * N - 1; l++) {
    while (s < S / 10 && r < 2 * N - 1) {
      s += A[r];
      r++;
    }

    if (s == S / 10 && s != 0) {
      yes = true;
      break;
    }

    s -= A[l];
  }

  if (yes) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}