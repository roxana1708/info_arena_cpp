#include <fstream>
#include <algorithm>

using namespace std;

#define max_n 100001

int n, m, v[max_n], arb[4*max_n] = {0}, lazy[4*max_n] = {0};

void construct(int st, int dr, int nod) {
    if(st > dr)
        return;

    if(st == dr) {
        arb[nod] = v[st];
        return;
    }

    int mid = (st + dr) / 2;
    construct(st, mid, 2*nod);
    construct(mid+1, dr, 2*nod+1);

    arb[nod] = max(arb[2*nod], arb[2*nod+1]);
}

void update(int nod, int st, int dr, int index, int val) {
    if(st > dr)
        return;

    if(st == dr) {
        arb[nod] = val;
        return;
    }

    int mid = (st + dr) / 2;
    if(index <= mid)
        update(2*nod, st, mid, index, val);
    else
        update(2*nod+1, mid+1, dr, index, val);
    arb[nod] = max(arb[2*nod], arb[2*nod+1]);
}

int query(int nod, int st, int dr, int l, int r) {
    if(dr < l || st > r)
        return arb[nod];

    if(lazy[nod]) {
        arb[nod] += lazy[nod];

        if(st != dr) {
            lazy[2*nod] += lazy[nod];
            lazy[2*nod+1] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if(l <= st && dr <= r)
        return arb[nod];

    int mid = (st + dr) / 2;
    int left_side = 0, right_side = 0;
    if(l <= mid) left_side = query(2*nod, st, mid, l, r);
    if(r > mid) right_side = query(2*nod+1, mid+1, dr, l, r);

    return max(left_side, right_side);
}

int main() {

    ifstream f("arbint.in");
    ofstream g("arbint.out");

    f >> n >> m;

    for(int i = 1; i <= n; i++) {
        f >> v[i];
    }

    construct(1, n, 1);

    int op, a, b;
    for(int i = 0; i < m; i++) {
        f >> op;
        switch (op) {
            case 0: {
                f >> a >> b;
                g << query(1, 1, n, a, b) << "\n";
                break;
            }
            case 1: {
                f >> a >> b;
                update(1, 1, n, a, b);
                break;
            }
            default:
                g << "Operatie Gresita";

        }
    }

    return 0;
}