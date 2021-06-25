#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int T;
  cin >> T;
  int L, X, Y;
  cin >> L >> X >> Y;
  int Q;
  cin >> Q;
  vector<int> E(Q);
  rep(i, Q) cin >> E[i];

  vector<double> ans(Q);
  rep(i, Q) {
    double rad = 2 * M_PI * ((double)E[i] / T);
    double y = -sin(rad) * (double)L / 2.0;
    double z = L / 2.0 - cos(rad) * (double)L / 2.0;
    double t = z / sqrt((double)X * (double)X + ((double)Y - y) * ((double)Y - y));
    ans[i] = 360.0 * (atan(t) / (2 * M_PI));
  }

  rep(i, Q) cout << ans[i] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}