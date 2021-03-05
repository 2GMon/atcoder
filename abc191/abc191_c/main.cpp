#include"bits/stdc++.h"
using namespace std;

void Main() {
  int H, W;
  cin >> H >> W;

  char S[H][W];
  int N[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> S[i][j];
      N[i][j] = 0;
    }
  }

  int n = 0;
  for (int i = 1; i < H - 1; i++) {
    for (int j = 1; j < W - 1; j++) {
      if (S[i][j] == '.') continue;

      if (S[i][j - 1] == '#' && S[i + 1][j] == '#' && S[i + 1][j - 1] == '.') N[i][j]++;
      if (S[i][j - 1] == '#' && S[i - 1][j] == '#' && S[i - 1][j - 1] == '.') N[i][j]++;
      if (S[i - 1][j] == '#' && S[i][j + 1] == '#' && S[i - 1][j + 1] == '.') N[i][j]++;
      if (S[i][j + 1] == '#' && S[i + 1][j] == '#' && S[i + 1][j + 1] == '.') N[i][j]++;

      if (S[i - 1][j - 1] == '#' && S[i - 1][j] == '#' && S[i][j - 1] == '.') N[i][j]++;
      if (S[i][j + 1] == '#' && S[i - 1][j + 1] == '#' && S[i - 1][j] == '.') N[i][j]++;
      if (S[i + 1][j] == '#' && S[i + 1][j + 1] == '#' && S[i][j + 1] == '.') N[i][j]++;
      if (S[i][j - 1] == '#' && S[i + 1][j - 1] == '#' && S[i + 1][j] == '.') N[i][j]++;

      if (S[i - 1][j] == '#' && S[i - 1][j + 1] == '#' && S[i][j + 1] == '.') N[i][j]++;
      if (S[i][j + 1] == '#' && S[i + 1][j + 1] == '#' && S[i + 1][j] == '.') N[i][j]++;
      if (S[i + 1][j] == '#' && S[i + 1][j - 1] == '#' && S[i][j - 1] == '.') N[i][j]++;
      if (S[i][j - 1] == '#' && S[i - 1][j - 1] == '#' && S[i - 1][j] == '.') N[i][j]++;

      for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
          if (x == 0 && y == 0) continue;
          N[i][j] -= N[i + y][j + x];
        }
      }
      N[i][j] = max(0, N[i][j]);
      if (N[i][j] > 0) n += N[i][j];
    }
  }

  cout << 4 + 2 * n << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}