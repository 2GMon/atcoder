#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    string s;
    cin >> s;
    if (s > "atcoder") cout << 0 << endl;
    else {
      bool success = false;
      for (int k = 1; k < s.length(); k++) {
        if (s[k] == 'a') continue;
        if (s[k] <= 't') {
          cout << k << endl;
          success = true;
          break;
        } else {
          cout << k - 1 << endl;
          success = true;
          break;
        }
      }
      if (!success) cout << -1 << endl;
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}