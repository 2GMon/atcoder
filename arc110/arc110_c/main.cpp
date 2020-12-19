#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;

  vector<int> P(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> P[i];
  }

  vector<int> ans;
  int find = 1;

  for (int i = 1; i <= N; i++) {
    if (P[i] == find) {
      for (int j = i - 1; j >= find; j--) {
        ans.push_back(j);
        int tmp = P[j + 1];
        P[j + 1] = P[j];
        P[j] = tmp;
      }
      find = i;
    }
  }

  if (ans.size() != N - 1) {
    cout << -1 << endl;
    return;
  }
  for (int i = 1; i <= N; i++) {
    if (P[i] != i) {
      cout << -1 << endl;
      return;
    }
  }

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