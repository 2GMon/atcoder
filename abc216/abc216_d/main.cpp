#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, M;
  cin >> N >> M;

  vector<queue<int>> a(M);
  vector<vector<int>> mem(N); // iが先頭にある筒のidx
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int tmp;
      cin >> tmp;
      a[i].push(tmp - 1);
    }
    mem[a[i].front()].push_back(i);
  }
  
  queue<int> q;
  for (int i = 0; i < N; i++) {
    if (mem[i].size() == 2) q.push(i);
  }

  while(!q.empty()) {
    int now = q.front(); q.pop();
    for (auto p : mem[now]) {
      a[p].pop();
      if (!a[p].empty()) {
        mem[a[p].front()].push_back(p);
        if (mem[a[p].front()].size() == 2) {
          q.push(a[p].front());
        }
      }
    }
  }
  for (auto p: a) {
    if (!p.empty()) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}