#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

#define inf 1e18+1
int n, k;
long long v[100001], st, dr;

long long solve(long long x) {
    long long val = 0;
    long long minim = inf;

    for (int i = 0; i <= n; ++i)
    {
        val += abs(v[i] - x);

        if (i >= k)
        {
            val -= abs(v[i - k] - x);
            minim = min(minim, val);
        }
    }
    return minim;
}

void cautare_binara() {
    while (st <= dr) {
        long long mij = (st + dr) / 2;
        if (solve(mij - 1) > solve(mij + 1))
            st = mij + 1;
        else
            dr = mij - 1;
    }
}

int main() {
    ifstream f ("pikachu.in");
    ofstream g ("pikachu.out");

    f >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        f >> v[i];
        st = min(st, v[i]);
        dr = max(dr, v[i]);
    }

    cautare_binara();
    g << solve(st);

    return 0;
}