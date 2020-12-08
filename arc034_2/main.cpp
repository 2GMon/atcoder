#include"bits/stdc++.h"
using namespace std;

void Main() {
  long long N;
  cin >> N;

  vector<long long> ans;
  for (long long i = max(N - 153, (long long)1); i <= N; i++) {
    long long x = i;
    long long a = x;
    while (x > 0) {
      a += x % 10;
      x /= 10;
    }
    if (a == N) ans.push_back(i);
  }

  cout << ans.size() << endl;
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