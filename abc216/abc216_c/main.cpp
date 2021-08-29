#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  ll N;
  cin >> N;

  vector<char> ans;
  while (N > 0) {
    if (N % 2 == 1) {
      N -= 1;
      ans.push_back('A');
    } else {
      N /= 2;
      ans.push_back('B');
    }
  }
  
  reverse(ans.begin(), ans.end());
  for (auto c: ans) {
    cout << c;
  }
  cout << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}