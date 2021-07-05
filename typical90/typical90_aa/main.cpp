#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  set<string> S;
  vector<int> ans;
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    if (S.find(s) == S.end()) {
      S.insert(s);
      ans.push_back(i);
    }
  }
  for (int a: ans) {
    cout << a << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}