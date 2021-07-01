#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

ll N, B;
ll ans = 0;

void dfs(int len, string str, int last) {
  if (str.size() == len) {
    ll f = 1;
    for (int i = 0; i < str.size(); i++) {
      f *= str[i] - '0';
    }
    if (f + B <= N) {
      string str_num = to_string(f + B);
      sort(str_num.begin(), str_num.end());
      reverse(str_num.begin(), str_num.end());
      if (str_num == str) ans++;
    }
    return;
  }
  for (int i = last; i >= 1; i--) {
    string str2 = str;
    str2 += '0' + i;
    dfs(len, str2, i);
  }
}

void Main() {
  cin >> N >> B;

  for (int i = 1; i <= 11; i++) {
    dfs(i, "", 9);
  }

  string b = to_string(B);
  bool success = false;
  for (int i = 0; i < b.size(); i++) if (b[i] == '0') success = true;
  if (success && N >= B) ans++;

  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}