#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

// mod. m での a^b
long long modpow(long long a, long long b, long long m) {
    long long ans = 1;
    while (b != 0) {
        if (b % 2 == 1)
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        b /= 2;
    }
    return ans;
}

void Main() {
  ll N;
  ll M;
  cin >> N >> M;

  cout << modpow(10, N, M * M) / M % M << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}