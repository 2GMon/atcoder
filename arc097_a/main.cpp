#include"bits/stdc++.h"
using namespace std;

void Main() {
  string s;
  cin >> s;
  int K;
  cin >> K;

  vector<string> subs;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < K && i + j < s.length(); j++) {
      subs.push_back(s.substr(i, j + 1));
    }
  }
  sort(subs.begin(), subs.end());
  unique(subs.begin(), subs.end());

/*
  for (auto ss: subs) {
    cout << ss << endl;
  }
*/

  cout << subs[K - 1] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}