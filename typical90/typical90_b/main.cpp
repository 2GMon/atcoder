#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  if (N % 2) {
    cout << endl;
    return;
  }

  for (int i = 0; i < (1 << N); i++) {
    vector<char> res;
    int l = 0, r = 0;
    for (int j = 1; j < 1 << N; j <<= 1) {
      if (i & j) {
        res.push_back(')');
        r++;
      } else {
        res.push_back('(');
        l++;
      }
    }
    if (r != l) continue;
    reverse(res.begin(), res.end());

    int sum = 0;
    int cond = true;
    for (int j = 0; j < N; j++) {
      if (res[j] == '(') sum++;
      else sum--;

      if (sum < 0) {
        cond = false;
        break;
      }
    }
    if (!cond) continue;

    for (auto r: res) cout << r;
    cout << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}