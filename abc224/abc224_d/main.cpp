#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int M;
  cin >> M;

  vector<vector<int>> G(10);
  for (int i = 1; i <= M; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int p; string s = "999999999";
  for (int i = 1; i <= 8; i++) {
    cin >> p;
    s[p - 1] = i + '0';
  }

  queue<string> q;
  q.push(s);
  map<string, int> d;
  d[s] = 0;
  while(q.size()) {
    string s = q.front(); q.pop();
    int v;
    for (int i = 1; i <= 9; i++) if(s[i - 1] == '9') v = i;

    for (auto u: G[v]) {
      string t = s;
      swap(t[u - 1], t[v - 1]);
      if (d.count(t)) continue;
      d[t] = d[s] + 1;
      q.push(t);
    }
  }

  if (d.count("123456789") == 0) cout << -1 << endl;
  else cout << d["123456789"] << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}