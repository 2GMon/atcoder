#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  vector<vector<int>> field(1002, vector<int>(1002, 0));
  for (int i = 0; i < N; i++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    field[ly][lx] += 1;
    field[ly][rx] -= 1;
    field[ry][lx] -= 1;
    field[ry][rx] += 1;
  }

  for (int y = 0; y <= 1000; y++) {
    for (int x = 1; x <= 1000; x++) {
      field[y][x] += field[y][x - 1];
    }
  }

  for (int x = 0; x <= 1000; x++) {
    for (int y = 1; y <= 1000; y++) {
      field[y][x] += field[y - 1][x];
    }
  }

  vector<ll> ans(N + 1, 0);
  for (int y = 0; y <= 1000; y++) {
    for (int x = 0; x <= 1000; x++) {
      ans[field[y][x]]++;
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << ans[i] << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}