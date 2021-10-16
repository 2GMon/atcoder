#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N;
  cin >> N;
  vector<char> S(N), T(N);
  for (int i = 0; i < N; i++) cin >> S[i];
  for (int i = 0; i < N; i++) cin >> T[i];

  vector<int> s, t;
  for (int i = 0; i < N; i++)
    if (S[i] == '0') s.push_back(i);
  for (int i = 0; i < N; i++)
    if (T[i] == '0') t.push_back(i);

  if (s.size() != t.size()) cout << -1 << endl;
  else {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != t[i]) ans++;
    }
    cout << ans << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}