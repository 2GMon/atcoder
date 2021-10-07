#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll INF = 1000000007;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]++;
  }

  ll ans = 1;
  vector<int> cnt(N + 1, 0);
  cnt[0] = 3;
  for (int i = 0; i < N; i++) {
    if (cnt[A[i] - 1] <= 0) {
      ans = 0;
      break;
    }

    ans *= cnt[A[i] - 1];
    ans %= INF;
    cnt[A[i] - 1]--;
    cnt[A[i]]++;
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