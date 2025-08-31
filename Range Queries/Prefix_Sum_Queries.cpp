#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long sum;       // suma total del segmento
    long long maxPrefix; // mayor prefix sum en el segmento
};

vector<long long> arr;
vector<Node> seg;

Node merge(Node a, Node b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.maxPrefix = max(a.maxPrefix, a.sum + b.maxPrefix);
    return res;
}

Node make_node(long long val) {
    return {val, max(0LL, val)}; // si quieres permitir negativos: {val, val}
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = make_node(arr[l]);
        return;
    }
    int m = (l + r) / 2;
    build(idx*2, l, m);
    build(idx*2+1, m+1, r);
    seg[idx] = merge(seg[idx*2], seg[idx*2+1]);
}

void update(int idx, int l, int r, int pos, long long val) {
    if (l == r) {
        arr[pos] = val;
        seg[idx] = make_node(val);
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(idx*2, l, m, pos, val);
    else update(idx*2+1, m+1, r, pos, val);
    seg[idx] = merge(seg[idx*2], seg[idx*2+1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return {0, LLONG_MIN/2};
    if (ql <= l && r <= qr) return seg[idx];
    int m = (l + r) / 2;
    Node left = query(idx*2, l, m, ql, qr);
    Node right = query(idx*2+1, m+1, r, ql, qr);
    return merge(left, right);
}

int main() {
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    seg.resize(4*n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 2) { // consulta
            int l, r;
            cin >> l >> r; // 0-indexado
            l--;r--;
            cout << query(1, 0, n-1, l, r).maxPrefix << "\n";
        } else if (type == 1) { // actualización
            int pos; long long val;
            cin >> pos >> val; // 0-indexado
            pos--;
            update(1, 0, n-1, pos, val);
        }
    }
}
