#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;

  double ans = 0;
  for (int i = 1; i <N; i++) {
    ans += double(N) / i;
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