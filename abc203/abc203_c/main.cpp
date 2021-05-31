#include"bits/stdc++.h"
using namespace std;

void Main() {
  long long N, K;
  cin >> N >> K;

  vector<pair<int, long long>> friends(N);
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;

    friends[i] = pair<long long, int>(A, B);
  }
  sort(friends.begin(), friends.end());
  long long now = 0;
  for (int i = 0; i < N; i++) {
    if (now + K >= friends[i].first) K += friends[i].second;
  }

  cout << now + K << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}