#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream f("flori2.in");
ofstream g("flori2.out");

struct crd {
    int x;
    int y;
} coord[1001];

int t, n, i, j, curr, maxim;
vector<double> pante;

double panta(int x1, int y1, int x2, int y2) {
    if (x1 == x2)
        return 10000001;
    else
        return (((y2 - y1 + 0.0) / (x2 - x1 + 0.0)));
}

void solve() {
    maxim = 2;
    for (i = 0; i < n; i++) {
        pante.clear();
        for (j = 0; j < n; j++) {
            if (i != j) {
                if(coord[i].y - coord[j].y == 0)
                    pante.push_back(0);
                else
                    pante.push_back(panta(coord[i].x, coord[i].y, coord[j].x, coord[j].y));
            }
        }

        sort(pante.begin(), pante.end());

        for (j = 0; j < (int)pante.size(); j++) {
            curr = 1;
            while(pante[j] == pante[j+1] && j+1 < (int)pante.size()) {
                curr++;
                j++;
            }

            maxim = max(maxim, curr+1);

        }
    }
    g << maxim << "\n";
}


int main() {
    f >> t;

    while(t--) {
        f >> n;

        for (i = 0; i < n; i++)
            f >> coord[i].x >> coord[i].y;

        if(n <= 2)
            g << n << "\n";
        else
            solve();
    }

    return 0;
}