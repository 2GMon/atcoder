#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

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

  UnionFind u = UnionFind(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    u.connect(a, b);
  }

  set<int> ans;
  for (int i = 0; i < N; i++) {
    ans.insert(u.root(i));
  }

  cout << ans.size() - 1 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}