#include"bits/stdc++.h"
using namespace std;

void Main() {
  string S;
  cin >> S;

  vector<int> must;
  for (int i = 0; i < 10; i++) {
    if (S[i] == 'o') must.push_back(i);
  }

  int ans = 0;
  for (int i = 0; i <= 9999; i++) {
    int a = i / 1000;
    int b = i % 1000 / 100;
    int c = i % 100 / 10;
    int d = i % 10;
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    // cout << a << b << c << d << endl;

    bool success = true;
    for (auto m: must) {
      if (s.find(m) == s.end()) {
        success = false;
        break;
      }
    }
    if (!success) {
      continue;
    }
    // cout << "success" << endl;
    for (auto m: must) {
      s.erase(m);
    }
    for (auto m: s) {
      if (S[m] == 'x') {
        success = false;
        break;
      }
    }
    // cout << "success" << endl;
    // cout <<  endl;
    if (success) ans++;
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