#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N, K;
  cin >> N >> K;

  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      ans += i * 100 + j;
    }
  }
  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}