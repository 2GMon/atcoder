#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  long long X;
  cin >> X;

  vector<long long> sum(N);
  for (int i = 0; i < N; i++) {
    sum[i] = (long long)A[i];
    if (i >= 1) sum[i] += sum[i - 1];
  }

  long long ans = N * (X / sum[N - 1]);
  long long nokori = X % sum[N - 1];
  for (int i = 0; i < N; i++) {
    if (sum[i] > nokori) {
      ans += i + 1;
      break;
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