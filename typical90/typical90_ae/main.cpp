#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  vector<int> W(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> W[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  int max_b = 50 * 51 / 2 + 50;
  vector<vector<int>> grundy(51, vector<int>(max_b + 1, 0));
  for (int w = 0; w <= 50; w++) {
    for (int b = 0; b <= max_b; b++) {
      vector<bool> mex(max_b + 1, true);
      if(w >= 1) mex[grundy[w - 1][b + w]] = false;
      if (b >= 2) {
        for (int i = 1; i <= b / 2; i++) mex[grundy[w][b - i]] = false;
      }
      for (int i = 0; i <= max_b; i++) {
        if (mex[i]) {
          grundy[w][b] = i;
          break;
        }
      }
    }
  }

  int xor_grundy = 0;
  for (int i = 0; i < N; i++) {
    xor_grundy ^= grundy[W[i]][B[i]];
  }

  if (xor_grundy != 0) cout << "First" << endl;
  else cout << "Second" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}