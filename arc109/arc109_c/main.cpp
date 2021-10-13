#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  s = s + s;
  for (int i = 0; i < k; i++) {
    string tmp = "";
    for (int j = 0; j < s.length() - 1; j += 2) {
      if (s[j] == s[j + 1]) {
        tmp += s[j];
      } else if (s[j] == 'P' && s[j + 1] == 'R') {
        tmp += s[j];
      } else if (s[j] == 'R' && s[j + 1] == 'S') {
        tmp += s[j];
      } else if (s[j] == 'S' && s[j + 1] == 'P') {
        tmp += s[j];
      } else {
        tmp += s[j + 1];
      }
    }
    s = tmp + tmp;
  }
  cout << s[0] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}