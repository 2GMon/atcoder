#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  vector<char> C(N);
  for (int i = 0; i < N; i++) cin >> C[i];

  vector<string> sc;
  string key[] = {"A", "B", "X", "Y"};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sc.push_back(key[i] + key[j]);
    }
  }

  int ans = N;
  for (string a : sc) {
    for (string b: sc) {
      if (a == b) continue;
      int tmp = 0;
      for (int i = 0; i < N; i++) {
        if (i < N - 1 && ((C[i] == a[0] && C[i + 1] == a[1]) || (C[i] == b[0] && C[i + 1] == b[1]))) {
          tmp++;
          i++;
        } else {
          tmp++;
        }
      }
      ans = min(ans, tmp);
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