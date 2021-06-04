#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, M;
  cin >> N >> M;

  vector<int> x(M), y(M);
  rep(i, M) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  vector<int> num(N, 1);
  vector<bool> red(N, false);
  red[0] = true;
  rep(i, M) {
    if (red[x[i]]) red[y[i]] = true;
    num[x[i]]--;
    num[y[i]]++;
    if (num[x[i]] == 0) red[x[i]] = false;
  }

  int ans = 0;
  rep(i, N) {
    if (red[i]) ans++;
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