#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;
  pair<int, string> M[N];

  for (int i = 0; i < N; i++) {
    string S;
    int T;
    cin >> S >> T;
    M[i] = pair<int, string>(T, S);
  }

  sort(M, M + N);
  cout << M[N - 2].second << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}