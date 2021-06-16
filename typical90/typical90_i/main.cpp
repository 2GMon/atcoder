#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  vector<int> X(N), Y(N);
  rep(i, N) cin >> X[i] >> Y[i];

  double ans = 0;
  for (int i = 0; i < N; i++) {
    vector<double> kaku;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int x = X[j] - X[i], y = Y[j] - Y[i];
      double angle = atan2(y, x) * 180 / M_PI;
      if (angle < 0) angle += 360;
      kaku.push_back(angle);
    }
    sort(kaku.begin(), kaku.end());

    for (int j = 0; j < kaku.size(); j++) {
      double target = kaku[j] + 180;
      if (target >= 360) target -= 360;
      int pos = lower_bound(kaku.begin(), kaku.end(), target) - kaku.begin();
      int idx1 = pos % kaku.size();
      int idx2 = (pos + kaku.size() - 1) % kaku.size();
      double angle1 = abs(kaku[j] - kaku[idx1]) >= 180 ? 360 - abs(kaku[j] - kaku[idx1]) : abs(kaku[j] - kaku[idx1]);
      double angle2 = abs(kaku[j] - kaku[idx2]) >= 180 ? 360 - abs(kaku[j] - kaku[idx2]) : abs(kaku[j] - kaku[idx2]);
      ans = max({ ans, angle1, angle2 });
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