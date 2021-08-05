#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  string s;
  cin >> s;

  ll notAns = 0;
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt++;
    if (i == N - 1 || s[i] != s[i + 1]) {
      notAns += cnt * (cnt + 1) / 2;
      cnt = 0;
    }
  }

  ll all = (ll)N * (N + 1) / 2;
  cout << all - notAns << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}