#include <fstream>

using namespace std;

ifstream f("transport.in");
ofstream g("transport.out");

int n, k, v[16001], maxim = 0, s = 0, mijl, copie_c, copie_s, i, j;

int transp(int capacitate) {
    j = 0;
    copie_s = s;
    for(i = 0; i < k; i++) {
        copie_c = capacitate;

        while(copie_c - v[j] >= 0) {
            copie_c -= v[j];
            copie_s -= v[j];
            j++;
        }
    }

    return copie_s <= 0;
}

int cautareBin(int st, int dr) {
    while(st < dr) {
        mijl = (st + dr) / 2;

        if(transp(mijl))
            dr = mijl;
        else
            st = mijl+1;
    }

    return st;
}

int main() {
    f >> n >> k;

    for(i = 0; i < n; i++) {
        f >> v[i];
        s += v[i];
        maxim = maxim < v[i] ? v[i] : maxim;
    }

    g << cautareBin(maxim, s);
    return 0;
}