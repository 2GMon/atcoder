#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N), W(M);
  for (int i = 0; i < N; i++) cin >> H[i];
  for (int i = 0; i < M; i++) cin >> W[i];

  sort(H.begin(), H.end());
  vector<int> A((N + 1) / 2, 0), B((N + 1) / 2, 0);
  
  for (int i = 0; i + 1 < N; i+= 2) A[i / 2 + 1] = A[i / 2] + H[i + 1] - H[i];
  for (int i = N - 2; i > 0; i -= 2) B[i / 2] = B[i / 2 + 1] + H[i + 1] - H[i];

  ll ans = (ll)1 << 60;
  for (int w: W) {
    int x = lower_bound(H.begin(), H.end(), w) - H.begin();
    if (x % 2 == 1) x -= 1;

    ans = min(ans, (ll)A[x / 2] + B[x / 2] + abs(H[x] - w));
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