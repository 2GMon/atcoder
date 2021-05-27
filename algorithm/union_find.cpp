#include"bits/stdc++.h"
using namespace std;

class UnionFind {
    public:
        vector<int> parent;

        UnionFind(int n) {
            parent = vector<int>(n, -1);
        }

        int root(int a) {
            if (parent[a] < 0) return a;
            else return parent[a] = root(parent[a]);
        }

        int size(int a) {
            return -parent[root(a)];
        }

        bool connect(int a, int b) {
            a = root(a);
            b = root(b);
            if (a == b) return false;

            if (size(a) < size(b)) swap(a, b);

            parent[a] += parent[b];
            parent[b] = a;
            return true;
        }
};

int main() {
    UnionFind u = UnionFind(4);
    cout << "root(0) = " << u.root(0) << ", size(0) = " << u.size(0) << endl;
    cout << "root(1) = " << u.root(1) << ", size(1) = " << u.size(1) << endl;
    cout << "root(2) = " << u.root(2) << ", size(2) = " << u.size(2) << endl;
    cout << "root(3) = " << u.root(3) << ", size(3) = " << u.size(3) << endl;
    cout << endl;
    u.connect(0, 1);
    cout << "root(0) = " << u.root(0) << ", size(0) = " << u.size(0) << endl;
    cout << "root(1) = " << u.root(1) << ", size(1) = " << u.size(1) << endl;
    cout << "root(2) = " << u.root(2) << ", size(2) = " << u.size(2) << endl;
    cout << "root(3) = " << u.root(3) << ", size(3) = " << u.size(3) << endl;
    cout << endl;
    u.connect(2, 3);
    cout << "root(0) = " << u.root(0) << ", size(0) = " << u.size(0) << endl;
    cout << "root(1) = " << u.root(1) << ", size(1) = " << u.size(1) << endl;
    cout << "root(2) = " << u.root(2) << ", size(2) = " << u.size(2) << endl;
    cout << "root(3) = " << u.root(3) << ", size(3) = " << u.size(3) << endl;
    cout << endl;
    u.connect(3, 0);
    cout << "root(0) = " << u.root(0) << ", size(0) = " << u.size(0) << endl;
    cout << "root(1) = " << u.root(1) << ", size(1) = " << u.size(1) << endl;
    cout << "root(2) = " << u.root(2) << ", size(2) = " << u.size(2) << endl;
    cout << "root(3) = " << u.root(3) << ", size(3) = " << u.size(3) << endl;
    return 0;
}