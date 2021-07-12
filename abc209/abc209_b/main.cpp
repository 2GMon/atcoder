#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  ll sum = 0;
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0) sum += A[i] - 1;
    else sum += A[i];
  }
  if (sum <= X) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}