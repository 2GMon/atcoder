#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  cin >> N >> K;

  vector<char> S(N + 1);
  rep(i, N) cin >> S[i + 1];

  vector<vector<int>> c(N + 2, vector<int>(26, -1));
  for (int i = N; i >= 1; i--) {
    for (int j = 0; j < 26; j++) {
      if (S[i] - 'a' == j) c[i][j] = i;
      else c[i][j] = c[i + 1][j];
    }
  }

  int pos = 1;
  for (int i = K; i > 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (c[pos][j] > 0 && N - c[pos][j] + 1 >= i) {
        cout << (char)('a' + j);
        pos = c[pos][j] + 1;
        break;
      }
    }
  }
  cout << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}