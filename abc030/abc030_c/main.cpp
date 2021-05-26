#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N, M;
  cin >> N >> M;

  int X, Y;
  cin >> X >> Y;

  vector<int> a(N), b(M);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> b[i];
  }

  int ans = 0;
  int pos = 0;
  int now = 0;
  while (true) {
    if (pos == 0) {
      auto l = lower_bound(a.begin(), a.end(), now);
      if (l == a.end()) break;
      now = *l + X;
      pos = 1;
    }
    if (pos == 1) {
      auto l = lower_bound(b.begin(), b.end(), now);
      if (l == b.end()) break;
      now = *l + Y;
      pos = 0;
      ans++;
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