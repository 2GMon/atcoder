#include"bits/stdc++.h"
using namespace std;

using P = pair<int, int>;

typedef long long ll;

void Main() {
  int H, W, N;
  cin >> H >> W >> N;
  map<int, vector<P>> mp;
  map<P, int> cell;
  for (int i = 0; i < N; i++) {
    int r, c, a;
    cin >> r >> c >> a;
    mp[-a].push_back({r, c});
    cell[P(r, c)] = i;
  }

  vector<int> ans(N);
  map<int, int> mxr, mxc;
  for (auto [_, p]: mp) {
    for (auto [r, c]: p) {
      int now = max(mxr[r], mxc[c]);
      ans[cell[P(r, c)]] = now;
    }

    for (auto [r, c]: p) {
      int now = ans[cell[P(r, c)]];
      ans[cell[P(r, c)]] = now;
      mxr[r] = max(mxr[r], now + 1);
      mxc[c] = max(mxc[c], now + 1);
    }
  }

  for (auto a: ans) {
    cout << a << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}