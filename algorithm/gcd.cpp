#include"bits/stdc++.h"
using namespace std;

template <typename T>
T gcd(T  a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <typename T>
T lcm(T  a, T b) {
    return b * (a / gcd(a, b));
}

// ax + by = g
template <typename T>
T extgcd(T a, T b, T* x, T* y) {
    if (b == 0) {
        *x = 1; *y = 0;
        return a;
    }
    T g = extgcd(b, a % b, x, y);
    T tmpx = *x;
    *x = *y;
    *y = tmpx - a / b * *y;
    return g;
}

int main() {
    cout << "gcd(5, 15) = " << gcd<int>(5, 15) << endl;
    cout << "gcd(9, 32) = " << gcd<int>(9, 32) << endl;
    cout << "gcd(12, 66) = " << gcd<int>(12, 66) << endl;
    cout << endl;

    cout << "lcm(12, 66) = " << lcm<int>(12, 66) << endl;
    cout << "lcm(12, 8) = " << lcm<int>(12, 8) << endl;
    cout << "lcm(8, 10) = " << lcm<int>(8, 10) << endl;
    cout << endl;

    int x, y;
    int g;
    g = extgcd<int>(12, 66, &x, &y);
    cout << "extgcd(12, 66) = 12 * " << x << " + 66 * " << y << " = " << g << endl;
    return 0;
}