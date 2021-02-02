#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  sort(A.begin(), A.end());

  int t = 0;
  long long sum = 0;
  for (int i = 0; i < N - 1; i++) {
    sum += A[i];
    if (sum * 2 < A[i + 1]) t = i + 1;
  }
  cout << N - t << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}