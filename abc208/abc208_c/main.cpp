#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  ll K;
  cin >> N >> K;

  ll base =  K / N;
  vector<int> a(N), sorted_a(N);
  map<int, ll> num;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sorted_a[i] = a[i];
    num[a[i]] = base;
  }

  sort(sorted_a.begin(), sorted_a.end());

  ll amari = K % N;
  for (int i = 0; i < amari; i++) {
    num[sorted_a[i]]++;
  }

  for (int i = 0; i < N; i++) {
    cout << num[a[i]] << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}