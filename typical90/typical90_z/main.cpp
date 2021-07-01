#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int N;
vector<vector<int>> edge;
vector<int> color;

void dfs(int i, int c) {
  color[i] = c;
  for (int n : edge[i]) {
    if (color[n] == -1) dfs(n, 1 - c);
  }
}

void Main() {
  cin >> N;
  edge = vector<vector<int>>(N + 1, vector<int>());
  color = vector<int>(N + 1, -1);
  for (int i = 0; i < N - 1; i++) {
    int A, B;
    cin >> A >> B;
    edge[A].push_back(B);
    edge[B].push_back(A);
  }

  dfs(1, 0);

  int col0 = 0;
  for (int i = 1; i <= N; i++) {
    if (color[i] == 0) col0++;
  }
  if (col0++ >= N / 2) {
    int num = 0;
    for (int i = 1; i <= N && num < N / 2; i++) {
      if (color[i] == 0) {
        cout << i << endl;
        num++;
      }
    }
  } else {
    int num = 0;
    for (int i = 1; i <= N && num < N / 2; i++) {
      if (color[i] == 1) {
        cout << i << endl;
        num++;
      }
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}