#include"bits/stdc++.h"
using namespace std;

int N;
vector<vector<vector<int>>> F;
vector<vector<int>> P;

void Main() {
  cin >> N;
  F = vector<vector<vector<int>>>(N, vector<vector<int>>(5, vector<int>(2)));
  P = vector<vector<int>>(N, vector<int>(11));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 2; k++) {
        cin >> F[i][j][k];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> P[i][j];
    }
  }

  long long ans = -1e18;
  for (int i = 1; i < (1 << 10); i++) {
    vector<int> cnt(N, 0);
    for (int j = 0; j < 10; j++) {
      if (i & (1 << j)) {
        for (int k = 0; k < N; k++) {
          cnt[k] += F[k][j / 2][j % 2];
        }
      }
    }

    long long tmp = 0;
    for (int k = 0; k < N; k++) {
      tmp += P[k][cnt[k]];
    }
    // cout << i << ": " << tmp << endl;
    ans = max(ans, tmp);
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