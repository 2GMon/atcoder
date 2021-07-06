#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int INF = 1000000000;

void Main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }

  int M;
  cin >> M;
  vector<vector<bool>> hate(N + 1, vector<bool>(N + 1, false));
  for (int i = 0; i < M; i++) {
    int X, Y;
    cin >> X >> Y;
    hate[X][Y] = true;
    hate[Y][X] = true;
  }

  vector<int> order;
  for (int i = 1; i <= N; i++) {
    order.push_back(i);
  }

  int ans = INF;
  do {
    int time = 0;
    bool success = true;
    for (int i = 1; i < N; i++) {
      if (hate[order[i]][order[i - 1]]) success = false;
    }
    for (int i = 0; i < N; i++) {
      time += A[order[i]][i + 1];
    }

    if (success) ans = min(ans, time);
  } while (next_permutation(order.begin(), order.end()));

  if (ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}