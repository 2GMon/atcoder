#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  string S;
  cin >> S;

  int len = S.length();
  if (S[len - 2] == 'e' && S[len - 1] == 'r') cout << "er" << endl;
  if (S[len - 3] == 'i' && S[len - 2] == 's' && S[len - 1] == 't') cout << "ist" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}