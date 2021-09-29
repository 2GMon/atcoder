#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const int NUM = 100010;
int N;
vector<int> C(NUM);
vector<vector<int>> G(NUM);
vector<int> colored(NUM, 0);

vector<int> ans;

void dfs(int pos, int prev = 0) {
  if (colored[C[pos]] == 0) ans.push_back(pos);
  colored[C[pos]]++;
  for (auto nxt : G[pos]) {
    if (nxt == prev) continue;
    dfs(nxt, pos);
  }
  colored[C[pos]]--;
}

void Main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> C[i];

  for (int i = 0; i < N - 1; i++) {
    int A, B;
    cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  dfs(1, 0);
  sort(ans.begin(), ans.end());
  for (auto a: ans) {
    cout << a << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}