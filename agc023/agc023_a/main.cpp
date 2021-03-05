#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<long long> sum(N + 1);
  map<long long, long long> m;
  sum[0] = 0;
  m[0]++;
  for (int i = 0; i < N; i++) {
    sum[i + 1] = sum[i] + A[i];
    m[sum[i + 1]]++;
  }

  long long ans = 0;
  for (auto v: m) {
    if (v.second > 0) ans += v.second * (v.second - 1) / 2;
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