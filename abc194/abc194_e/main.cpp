#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> cnt(N + 1, 0);

  int ans = 1e7;
  for (int i = 0; i < M; i++) {
    cnt[A[i]]++;
  }
  for (int i = 0; i <= N; i++) {
    if (cnt[i] == 0) {
      ans = min(ans, i);
      break;
    }
  }

  for (int j = 0; j < N - M; j++) {
    int l = A[0 + j];
    cnt[l]--;

    int r = A[M + j];
    cnt[r]++;
    if (cnt[l] == 0) {
      ans = min(l, ans);
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