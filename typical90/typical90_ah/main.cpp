#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  cin >> N >> K;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  map<int, int> num;
  int ans = 0;
  int l = 0, r = 0;
  int k = 0;
  while(l < N) {
    while(r < N && k <= K) {
      num[a[r]]++;
      if (num[a[r]] == 1) k++;
      r++;
    }
    if (k <= K) ans = max(ans, r - l);
    else ans = max(ans, r - 1 - l);
    num[a[l]]--;
    if (num[a[l]] == 0) k--;
    l++;
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