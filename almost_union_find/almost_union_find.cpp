#include <bits/stdc++.h>
using namespace std;

class AlmostUnionFind {
private:
    vector<int> parent;
    vector<int> sz;
    vector<long long> sum;
    vector<int> id;

    int nodeCount;

public:
    AlmostUnionFind(int n, int m) {
        // Tối đa tạo thêm 1 node cho mỗi move
        int maxNodes = n + m + 5;

        parent.resize(maxNodes);
        sz.assign(maxNodes, 0);
        sum.assign(maxNodes, 0);
        id.resize(n + 1);

        nodeCount = n;

        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            sz[i] = 1;
            sum[i] = i;

            // Ban đầu value i được đại diện bởi node i
            id[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int p, int q) {
        int rp = find(id[p]);
        int rq = find(id[q]);

        if (rp == rq)
            return;

        // Có thể union by size
        if (sz[rp] > sz[rq])
            swap(rp, rq);

        parent[rp] = rq;

        sz[rq] += sz[rp];
        sum[rq] += sum[rp];
    }

    void moveElement(int p, int q) {
        int rp = find(id[p]);
        int rq = find(id[q]);

        if (rp == rq)
            return;

        // Remove p khỏi set cũ
        sz[rp]--;
        sum[rp] -= p;

        // Tạo node mới đại diện cho p
        ++nodeCount;

        id[p] = nodeCount;

        parent[nodeCount] = rq;
        sz[nodeCount] = 1;
        sum[nodeCount] = p;

        // Add p vào set mới
        sz[rq]++;
        sum[rq] += p;
    }

    pair<int, long long> query(int p) {
        int root = find(id[p]);

        return {
            sz[root],
            sum[root]
        };
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    // Multiple test cases cho tới EOF
    while (cin >> n >> m) {

        AlmostUnionFind dsu(n, m);

        while (m--) {
            int type;
            cin >> type;

            if (type == 1) {
                int p, q;
                cin >> p >> q;

                dsu.unite(p, q);

            } else if (type == 2) {
                int p, q;
                cin >> p >> q;

                dsu.moveElement(p, q);

            } else {
                int p;
                cin >> p;

                auto [count, total] = dsu.query(p);

                cout << count << ' ' << total << '\n';
            }
        }
    }

    return 0;
}