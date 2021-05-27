#include"bits/stdc++.h"
using namespace std;

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
  int N;
  cin >> N;

  vector<int> f(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> f[i];
  }

  UnionFind u = UnionFind(N + 1);
  for (int i = 1; i <= N; i++) {
    u.connect(i, f[i]);
  }

  set<int> s;
  for (int i = 1; i <= N; i++) {
    s.insert(u.root(i));
  }

  long long const mod = 998244353;
  long long a = 2;
  long long n = s.size();
  long long result = 1;
  while (n > 0) {
      if (n & 1) result = result * a % mod;
      a = a * a % mod;
      n >>= 1;
  }
  cout << result - 1 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}