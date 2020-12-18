#include"bits/stdc++.h"
using namespace std;

int N, M;
vector<vector<int>> a, ans;
vector<vector<bool>> visited;

void show_ans() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}

void update_ans(int i, int j) {
  visited[i][j] = true;

  ans[i][j] = min(a[i][j - 1], a[i - 1][j]);
  ans[i][j] = min(ans[i][j], a[i][j + 1]);
  ans[i][j] = min(ans[i][j], a[i + 1][j]);

  a[i][j - 1] -= ans[i][j];
  a[i][j + 1] -= ans[i][j];
  a[i - 1][j] -= ans[i][j];
  a[i + 1][j] -= ans[i][j];
}

void Main() {
  cin >> N >> M;

  a = vector<vector<int>>(N, vector<int>(M, 0));
  visited = vector<vector<bool>>(N, vector<bool>(M, false));
  ans = vector<vector<int>>(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
      if (i == 0 || i == N - 1 || j == 0 || j == M - 1) visited[i][j] = true;
    }
  }

  int i = 1, j = 1;
  while (visited[i][j] == false) {
    // 右
    while (j < M - 1 && visited[i][j] == false) {
      update_ans(i, j);
      j++;
    }
    i++;
    j--;
    // 下
    while (i < N - 1 && visited[i][j] == false) {
      update_ans(i, j);
      i++;
    }
    i--;
    j--;
    // 左
    while (j > 0 && visited[i][j] == false) {
      update_ans(i, j);
      j--;
    }
    i--;
    j++;
    // 上
    while (i > 0 && visited[i][j] == false) {
      update_ans(i, j);
      i--;
    }
    i++;
    j++;
  }

  show_ans();
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}