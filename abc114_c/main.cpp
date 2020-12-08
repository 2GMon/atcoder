#include"bits/stdc++.h"
using namespace std;
int N;

int dfs(long long i) {
  if (i > N) return 0;

  int ret = 0;
  bool san = false;
  bool go = false;
  bool shichi = false;
  long long j = i;
  while (j / 10 > 0) {
    if (j % 10 == 3) san = true;
    if (j % 10 == 5) go = true;
    if (j % 10 == 7) shichi = true;
    j /= 10;
  }
  if (j % 10 == 3) san = true;
  if (j % 10 == 5) go = true;
  if (j % 10 == 7) shichi = true;

  if (san && go && shichi) ret = 1;
  ret += dfs(i * 10 + 3);
  ret += dfs(i * 10 + 5);
  ret += dfs(i * 10 + 7);

  return ret;
}

void Main() {
  cin >> N;

  cout << dfs(0) << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}