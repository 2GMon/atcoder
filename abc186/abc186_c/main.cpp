#include"bits/stdc++.h"
using namespace std;

int N;

void Main() {
  cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    bool not7 = true;

    stringstream ss;
    ss << std::dec << i;
    string s = ss.str();
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '7') {
        not7 = false;
        break;
      }
    }

    ss << std::oct << i;
    s = ss.str();
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '7') {
        not7 = false;
        break;
      }
    }

    if (not7) ans++;
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