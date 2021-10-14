#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i <= N; i++) {
    int j = (N - i) * 4 - (M - 2 * i);
    int k = (M - 2 * i) - (N - i) * 3;
    if (j >= 0 && k >= 0) {
      cout << i << " " << j << " " << k << endl;
      return;
    }
  }
  cout << "-1 -1 -1" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}