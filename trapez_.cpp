#include <fstream>
#include <algorithm>

using namespace std;

#define NEDEF -2000000000

struct coord {
    double x;
    double y;
} coordonate[1001];

int main() {
    std::ifstream f("trapez.in");
    std::ofstream g("trapez.out");

    int n;
    std::ios::sync_with_stdio(false);

    f >> n;
    double panta[n * (n - 1) / 2];
    int k = 0;
    for (int i = 0; i < n; i++)
        f >> coordonate[i].x >> coordonate[i].y;

    for(int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(coordonate[j].x - coordonate[i].x != 0) {
                if(coordonate[j].x > coordonate[i].x) {
                    panta[k] = ((coordonate[j].y - coordonate[i].y) / (coordonate[j].x - coordonate[i].x));
                }
                else {
                    panta[k] = ((coordonate[i].y - coordonate[j].y) / (coordonate[i].x - coordonate[j].x));
                }
            }
            else {
                panta[k] = NEDEF;
            }
            k++;
        }
    }

    sort(panta, panta+k);

    int sol = 0;
    int nr = 1;

    for(int i = 0; i < k-1; i++) {
        if (panta[i] == panta[i + 1]) {
            nr++;
        }
        else {
            sol += nr * (nr - 1) / 2;
            nr = 1;
        }
    }

    g << sol;
    return 0;
}