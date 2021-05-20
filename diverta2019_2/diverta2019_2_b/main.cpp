#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;

  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  map<pair<int, int>, int> m;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      m[pair<int, int>(x[i] - x[j], y[i] - y[j])]++;
    }
  }

  int max_group = 0;
  for (auto tmp: m) {
    max_group = max(max_group, tmp.second);
  }

  cout << max(N - max_group, 1) << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}