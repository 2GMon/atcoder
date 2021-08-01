#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= S; j++) {
      if (j - A[i] >= 0) dp[i + 1][j] = dp[i][j - A[i]];
      if (j - B[i] >= 0 && dp[i + 1][j] == false) dp[i + 1][j] = dp[i][j - B[i]];
    }
  }
  if (dp[N][S] == false) {
    cout << "Impossible" << endl;
    return;
  }

  vector<char> reverse_ans;
  int price = S;
  for (int i = N; i > 0; i--) {
    if (price - A[i - 1] >= 0 && dp[i - 1][price - A[i - 1]]) {
      reverse_ans.push_back('A');
      price -= A[i - 1];
    } else {
      reverse_ans.push_back('B');
      price -= B[i - 1];
    }
  }

  reverse(reverse_ans.begin(), reverse_ans.end());
  for (auto c : reverse_ans) cout << c;
  cout << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}