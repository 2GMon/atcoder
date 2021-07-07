#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

template <typename T>
class RangeMinimumQuery {
  const T INF = numeric_limits<T>::max();
  int n; // 葉の数
  vector<T> seg;

public:
  void init(int sz) {
    int x = 1;
    while (x < sz) {
      x *= 2;
    }
    n = x;
    seg = vector<T>(n * 2, INF);
  }

  void update(int i, T x) {
    i = n - 1 + i;
    seg[i] = x;

    while (i > 0) {
      i = (i - 1) / 2;
      seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
  }

  // [a, b)の最小値
  // k = 現在見ているノード, l = 見ているノードがカバーする葉の一番左, r = 見ているノードがカバーする葉の一番右 + 1
  T query(int a, int b, int k = -1, int l = -1, int r = -1) {
    if (k == -1) k = 0;
    if (l == -1) l = 0;
    if (r == -1) r = n;
    if (r <= a || b <= l) { // [l, r)が[a, b)の外にある
      return INF;
    } else if (a <= l && r <= b) { // [l, r)が[a, b)に完全に含まれる
      return seg[k];
    } else { // [l, r)が[a, b)に一部含まれる
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

      return min(vl, vr);
    }
  }
};

template <typename T>
class RangeUpdatedMinimumQuery {
  const T INF = numeric_limits<T>::max();
  int n; // 葉の数
  vector<T> seg, lazy;

public:
  void init(int sz) {
    int x = 1;
    while (x < sz) {
      x *= 2;
    }
    n = x;
    seg = vector<T>(n * 2, INF);
    lazy = vector<T>(n * 2, INF);
  }

  // 更新の遅延評価
  void eval(int k) {
    if (lazy[k] == INF) return; // 更新するものがない場合
    if (k < n - 1) { // 更新対象のノードが葉でない場合は子に伝播
      lazy[k * 2 + 1] = lazy[k];
      lazy[k * 2 + 2] = lazy[k];
    }
    // ノード自分自身を更新
    seg[k] = lazy[k];
    lazy[k] = INF;
  }

  // [a, b)をxに更新する
  // k = 現在見ているノード, l = 見ているノードがカバーする葉の一番左, r = 見ているノードがカバーする葉の一番右 + 1
  void update(int a, int b, T x, int k, int l, int r) {
    eval(k); // 以前の遅延評価分を更新。(ここで更新しないと以前の更新が消えてしまう)
    if (a <= l && r <= b) { // [l, r)が[a, b)に完全に含まれる
      lazy[k] = x;
      eval(k);
    } else if (a < r && l < b) { // [l, r)が[a, b)に一部含まれる
      update(a, b, x, k * 2 + 1, l, (l + r) / 2);
      update(a, b, x, k * 2 + 2, (l + r) / 2, r);
      seg[k] = min(seg[k * 2 + 1], seg[k * 2 + 2]);
    }
  }

  // [a, b)の最小値
  // k = 現在見ているノード, l = 見ているノードがカバーする葉の一番左, r = 見ているノードがカバーする葉の一番右 + 1
  T query(int a, int b, int k = -1, int l = -1, int r = -1) {
    if (k == -1) k = 0;
    if (l == -1) l = 0;
    if (r == -1) r = n;
    eval(k);

    if (r <= a || b <= l) { // [l, r)が[a, b)の外にある
      return INF;
    } else if (a <= l && r <= b) { // [l, r)が[a, b)に完全に含まれる
      return seg[k];
    } else { // [l, r)が[a, b)に一部含まれる
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

      return min(vl, vr);
    }
  }
};