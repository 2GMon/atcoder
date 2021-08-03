#include"bits/stdc++.h"
using namespace std;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

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