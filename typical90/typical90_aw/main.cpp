#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

struct edge { int from, to; ll cost; };

bool comp (const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

class UnionFind {
    public:
        vector<int> parent;

        UnionFind(int n) {
            parent = vector<int>(n, -1);
        }

        int root(int a) {
            if (parent[a] < 0) return a;
            else return parent[a] = root(parent[a]);
        }

        int size(int a) {
            return -parent[root(a)];
        }

        bool connect(int a, int b) {
            a = root(a);
            b = root(b);
            if (a == b) return false;

            if (size(a) < size(b)) swap(a, b);

            parent[a] += parent[b];
            parent[b] = a;
            return true;
        }
};

void Main() {
  int N, M;
  cin >> N >> M;
  vector<ll> C(M);
  vector<int> L(M), R(M);

  vector<edge> edges;
  for (int i = 0; i < M; i++) {
    cin >> C[i] >> L[i] >> R[i];
    edges.push_back({ L[i] - 1, R[i], C[i] });
  }

  sort(edges.begin(), edges.end(), comp);
  UnionFind u(N + 1);
  ll ans = 0;
  for (int i = 0; i < M; i++) {
    edge e = edges[i];
    if (u.root(e.from) != u.root(e.to)) {
      u.connect(e.from, e.to);
      ans += e.cost;
    }
  }

  bool fail = false;
  for (int i = 1; i <= N; i++) {
    if (u.root(0) != u.root(i)) fail = true;
  }

  if (fail) cout << -1 << endl;
  else cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}