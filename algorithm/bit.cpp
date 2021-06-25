#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

class BIT {
public:
  int size_ = 1;
  vector<ll> bit;

  void init(int size) {
    size_ = size + 2;
    bit.resize(size_ + 2, 0);
  }
  void add(int pos, ll x) {
    pos++;
    while (pos <= size_) {
      bit[pos] += x;
      pos += (pos & -pos);
    }
  }
  ll sum(int pos) {
    ll s = 0; pos++;
    while (pos >= 1) {
      s += bit[pos];
      pos -= (pos & -pos);
    }
    return s;
  }
};