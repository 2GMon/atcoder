#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  vector<int> AB(N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    AB[i] = A[i] + B[i];
    ans -= B[i];
  }

  sort(AB.rbegin(), AB.rend());
  for (int i = 0; i < N; i += 2) {
    ans += AB[i];
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