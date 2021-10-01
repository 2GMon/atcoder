#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];

  long long ans = 0;
  for (int i = 1; i < N; i++) {
    if (a[i - 1] + a[i] > x) {
      long long over = a[i - 1] + a[i] - x;
      ans += over;
      a[i] = max((long long)0, a[i] - over);
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