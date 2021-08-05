#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, M;
  cin >> N >> M;;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (auto g : G[i]) {
      if (g < i) cnt++;
    }
    if (cnt == 1) ans++;
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