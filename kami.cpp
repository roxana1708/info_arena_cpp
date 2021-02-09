#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, t, arb[100000000], v[100000000], suma, maxim = 0;

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

    if(st >= l && dr <= r) {
        if(arb[nod] >= suma)
            return nod;
        else
            suma += arb[nod];
    }

    /*
    if(arb[nod] < suma)
        return 0;
    */

    int mid = (st + dr) / 2;
    int left_side = 0, right_side = 0;

    if(arb[2*nod] < suma)
        left_side = 0;
    else {
        if (l <= mid)
            left_side = query(2 * nod, st, mid, l, r);
    }

    if(arb[2*nod+1] < suma)
        right_side = 0;
    else {
        if (r > mid)
            right_side = query(2 * nod + 1, mid + 1, dr, l, r);
    }

    return max(left_side, right_side);

}


int main() {
    ifstream f("kami.in");
    ofstream g("kami.out");

    f >> n;

    for(int i = 1; i <= n; i++) {
        f >> v[i];
        maxim = max(maxim, v[i]);
    }

    construct(1, n, 1);

    /*

    f >> t;


    int op, x, val, b;
    for(int i = 0; i < t; i++) {
        f >> op;
        switch(op) {
            case 0: {
                f >> x >> val;
                update(1, 1, n, x, val);
                break;
            }
            case 1: {
                f >> b;
                g << query(1, 1, n, 1, b) << "\n";
                break;
            }
            default:
                g << "Operatie Gresita";

        }
    }
*/
    return 0;
}