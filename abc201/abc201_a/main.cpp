#include"bits/stdc++.h"
using namespace std;

void Main() {
  int A[3];
  for (int i = 0; i < 3; i++) {
    cin >> A[i];
  }
  sort(A, A + 3);
  if (A[1] - A[0] == A[2] - A[1]) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}