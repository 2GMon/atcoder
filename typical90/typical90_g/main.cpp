#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int Q;
  cin >> Q;
  vector<int> B(Q);
  rep(i, Q) cin >> B[i];

  sort(A.begin(), A.end());

  rep(i, Q) {
    int pos = lower_bound(A.begin(), A.end(), B[i]) - A.begin();

    if (pos == 0) cout << A[0] - B[i] << endl;
    else if (pos <= N - 1) cout << min(A[pos] - B[i], B[i] - A[pos - 1]) << endl;
    else cout << B[i] - A[N - 1] << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}