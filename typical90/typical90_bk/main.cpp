#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> P(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> P[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i < (1 << H); i++) {
    vector<int> selectedRow;
    for (int j = 0; j < 8; j++) {
      if (i & (1 << j)) selectedRow.push_back(j);
    }

    vector<int> nums;
    for (int j = 0; j < W; j++) {
      int num = P[selectedRow[0]][j];
      bool correct = true;
      for (int k = 1; k < selectedRow.size(); k++) {
        if (num != P[selectedRow[k]][j]) correct = false;
      }
      if (correct) nums.push_back(num);
    }

    map<int, int> count;
    int max_count = 0;
    for (auto n : nums) {
      count[n]++;
      max_count = max(max_count, count[n]);
    }
    ans = max(ans, (int)selectedRow.size() * max_count);
  }
  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}