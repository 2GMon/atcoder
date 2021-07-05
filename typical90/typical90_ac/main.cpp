#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class RangeMaximumQuery {
private:
  int sz;
  std::vector<int> seg;
  std::vector<int> lazy;

  void push(int k) {
    if (k < sz) {
      lazy[k * 2] = max(lazy[k * 2], lazy[k]);
      lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
    }
    seg[k] = max(seg[k], lazy[k]);
    lazy[k] = 0;
  }

  void update(int a, int b, int x, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l)
      return;
    if (a <= l && r <= b) {
      lazy[k] = x;
      push(k);
      return;
    }
    update(a, b, x, k * 2, l, (l + r) >> 1);
    update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
    seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
  }

  int range_max(int a, int b, int k, int l, int r) {
    push(k);
    if (r <= a || b <= l)
      return 0;
    if (a <= l && r <= b)
      return seg[k];
    int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
    int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
    return max(lc, rc);
  }

public:
  RangeMaximumQuery() : sz(0), seg(), lazy(){};

  RangeMaximumQuery(int N) {
    sz = 1;
    while (sz < N) {
      sz *= 2;
    }
    seg = std::vector<int>(sz * 2, 0);
    lazy = std::vector<int>(sz * 2, 0);
  }

  void update(int l, int r, int x) {
    update(l, r, x, 1, 0, sz);
  }

  int range_max(int l, int r) {
    return range_max(l, r, 1, 0, sz);
  }
};

void Main()
{
  int W, N;
  cin >> W >> N;

  RangeMaximumQuery seg(W);
  for (int i = 0; i < N; i++) {
    int L, R;
    cin >> L >> R;
    int height = seg.range_max(L - 1, R) + 1;
    seg.update(L - 1, R, height);
    cout << height << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}