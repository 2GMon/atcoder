#include"bits/stdc++.h"
using namespace std;

int N;
vector<long long> A;

void Main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.rbegin(), A.rend());

  long long ans = 0;
  long long j = N - 1;
  for (int i = 0; i <= (N - 1 - i); i++) {
    ans += A[i] * j;
    ans += A[N - 1 - i] * (-j);
    j -= 2;
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