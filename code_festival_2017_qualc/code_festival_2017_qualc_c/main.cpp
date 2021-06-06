#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  string s;
  cin >> s;

  int i = 0, j = s.length() - 1;
  int ans = 0;
  while (i <= j) {
    if (s[i] == s[j]) {
      i++; j--;
    } else if (s[i] == 'x' && s[j] != 'x') {
      ans++;
      i++;
    } else if (s[i] != 'x' && s[j] == 'x') {
      ans++;
      j--;
    } else if (s[i] != s[j]) {
      cout << -1 << endl;
      return;
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