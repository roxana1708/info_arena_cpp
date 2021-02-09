#include <fstream>
#include <algorithm>

using namespace std;

#define max_n 100001

int n, t, v[max_n], arb[4*max_n] = {0}, lazy[4*max_n] = {0};

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


int query(int nivel) {
    int poz = nivel - 1;
    int suma = arb[nivel];

    while(poz > 0)
}


void suma(int nod, int st, int dr, int l, int r, int nr_add) {

    if(lazy[nod] != 0) {
        arb[nod] += lazy[nod];

        if(st != dr) {
            lazy[2*nod] += lazy[nod];
            lazy[2*nod+1] += lazy[nod];
        }

        lazy[nod] = 0;
    }

    if(st > dr || st > r || dr < l)
        return;

    if(st >= l && dr <= r) {
        arb[nod] += nr_add;

        if(st != dr) {
            lazy[nod*2] += nr_add;
            lazy[nod*2+1] += nr_add;
        }

        return;
    }

    int mid = (st + dr) / 2;
    suma(2*nod, st, mid, l, r, nr_add);
    suma(2*nod+1, mid+1, dr, l, r, nr_add);

    arb[nod] = max(arb[2*nod], arb[2*nod+1]);

}

int main() {
    ifstream f("mit.in");
    ofstream g("mit.out");

    f >> n >> t;

    int x;
    for(int i = 1; i <= n; i++) {
        f >> v[i];
    }

    construct(1, n, 1);

    int op, a, b;
    for(int i = 0; i < t; i++) {
        f >> op;
        switch(op) {
            case 1: {
                f >> a >> b;
                g << query(1, 1, n, a, b) << "\n";
                break;
            }
            case 2: {
                f >> a >> b >> x;
                suma(1, 1, n, a, b, x);
                break;
            }
            default:
                g << "Operatie Gresita";

        }
    }

    return 0;
}