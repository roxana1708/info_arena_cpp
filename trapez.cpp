#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

struct coord {
    int x;
    int y;
} coordonate[1001];


double p(int x1, int y1, int x2, int y2) {
    if (x1 == x2)
        return 10000001;
    else
        return (((y2 - y1 + 0.0) / (x2 - x1 + 0.0)));
}

int main() {
    std::ifstream f("trapez.in");
    std::ofstream g("trapez.out");

    int n, curr = 1, sol = 0;
    f >> n;

    for(int i = 1; i <= n; i++)
        f >> coordonate[i].x >> coordonate[i].y;

    vector<double> panta;

    for(int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if(coordonate[i].y - coordonate[j].y == 0)
                panta.push_back(0);
            else
                panta.push_back(p(coordonate[i].x, coordonate[i].y, coordonate[j].x, coordonate[j].y));
        }
    }

    sort(panta.begin(), panta.end());

    for(int j = 1; j < panta.size(); j++) {
        if(panta[j] == panta[j-1])
            curr++;
        else {
            sol += curr * (curr-1) / 2;
            curr = 1;
        }
    }

    g << sol << "\n";
    f.close();
    g.close();
    return 0;
}