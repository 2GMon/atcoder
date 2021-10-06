#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

ll cost(vector<ll> a, vector<ll> b) {
  ll res = 1e18;
  for (auto i: a) {
    int pos = lower_bound(b.begin(), b.end(), i) - b.begin();
    if (pos < b.size()) {
      res = min({res, abs(i - b[pos]), abs(i - b[pos - 1])});
    } else if (b.size() > 0) {
      res = min({res, abs(i - b[b.size() - 1])});
    }
  }
  return res;
}

void Main() {
  int N;
  cin >> N;
  vector<ll> R, G, B;
  for (int i = 0; i < 2 * N; i++) {
    ll a;
    char c;
    cin >> a >> c;
    if (c == 'R') R.push_back(a);
    if (c == 'G') G.push_back(a);
    if (c == 'B') B.push_back(a);
  }

  if (R.size() % 2 == 0 && G.size() % 2 == 0 && B.size() % 2 == 0) {
    cout << 0 << endl;
    return;
  }
  sort(R.begin(), R.end());
  sort(G.begin(), G.end());
  sort(B.begin(), B.end());
  ll rg = cost(R, G), rb = cost(R, B), gb = cost(G, B);
  if (R.size() % 2 == 0) {
    cout << min(rg + rb, gb) << endl;;
  } else if (G.size() % 2 == 0) {
    cout << min(rg + gb, rb) << endl;;
  } else if (B.size() % 2 == 0) {
    cout << min(rb + gb, rg) << endl;;
  }

  vector<ll> tmp;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}