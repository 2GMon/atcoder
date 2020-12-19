#include"bits/stdc++.h"
using namespace std;

vector<long long> node(2 * 4194304 - 1);

void update(long long i, long long Y) {
  node[i] = node[i] ^ Y;
  if (i > 0) {
    update((i - 1) / 2, Y);
  }
}

long long query(int a, int b, int i, int l, int r) {
  if (r <= a || b <= l) return 0;
  if (a <= l && r <= b) return node[i];
  else {
    long long left = query(a, b, i * 2 + 1, l, (l + r) / 2);
    long long right = query(a, b, i * 2 + 2, (l + r) / 2, r);
    return left ^ right;
  }
}

void Main() {
  int N, Q;
  cin >> N >> Q;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  // セグメント木の初期化
  long long leaf_size = 2;
  while (leaf_size < N) {
    leaf_size *= 2;
  }
  for (int i = 0; i < N; i++) {
    node[leaf_size - 1 + i] = A[i];
  }
  for (int i = leaf_size - 2; i >= 0; i--) {
    node[i] = node[i * 2 + 1] ^ node[i * 2 + 2];
  }

  // クエリの処理
  for (int q = 0; q < Q; q++) {
    int T;
    long long X, Y;
    cin >> T >> X >> Y;
    X--;
    if (T == 1) {
      // セグメント木の更新
      update(leaf_size - 1 + X, Y);
    } else {
      // クエリ結果の表示
      cout << query(X, Y, 0, 0, leaf_size) << endl;
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}