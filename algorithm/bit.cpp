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
  void add(int pos, long long x) {
    pos++;
    while (pos <= size_) {
      bit[pos] += x;
      pos += (pos & -pos);
    }
  }
  long long sum(int pos) {
    long long s = 0; pos++;
    while (pos >= 1) {
      s += bit[pos];
      pos -= (pos & -pos);
    }
    return s;
  }
};