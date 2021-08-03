#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

ll base8to10(string N) {
  ll ans = 0, x = 1, pos = N.size();;
  for (int i = pos - 1; i >= 0; i--) {
    ans += (ll)(N[i] - '0') * x;
    x *= 8;
  }
  return ans;
}

string llto9(ll N) {
  if (N == 0) {
    return "0";
  }
  string ans;
  while (N > 0) {
    char c = ((N % 9)) + '0';
    ans = c + ans;
    N /= 9;
  }
  return ans;
}

void Main() {
  string N;
  int K;
  cin >> N >> K;

  for (int i = 0; i < K; i++) {
    ll n = base8to10(N);
    N = llto9(n);
    for (int j = 0; j < N.size(); j++) {
      if (N[j] == '8') N[j] = '5';
    }
  }
  cout << N << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}