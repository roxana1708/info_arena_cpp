#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <iomanip>


using namespace std;



struct Point {

    int x;

    int y;

};



const int MAXN = 2000;

const double INF = 1e9;

Point a[1 + MAXN * 2];



double dist[1 + MAXN * 2];





inline double get_dist (Point a, Point b) {

    return sqrt (1LL * (a.x - b.x) * (a.x - b.x) + 1LL * (a.y - b.y) * (a.y - b.y));

}



int main() {

    int n, m, i, j, best;



    freopen ("retea2.in", "r", stdin);

    freopen ("retea2.out", "w", stdout);



    cin >> n >> m;

    for (i = 1; i <= n + m; i++)

        cin >> a[i].x >> a[i].y;



    dist[1] = -1;

    for (i = n + 1; i <= n + m; i++)

        dist[i] = get_dist(a[1], a[i]);



    double sol = 0;

    for (i = 2; i <= n + m; i++) {

        double mn = INF;

        for (j = 1; j <= n + m; j++)

            if (dist[j] != -1 && mn > dist[j]) {

                best = j;

                mn = dist[j];

            }

        sol += mn;

        dist[best] = -1;

        for (j = 2; j <= n + m; j++)

            dist[j] = min (dist[j], get_dist (a[best], a[j]));

    }



    cout << fixed << setprecision(6) << sol << "\n";



    return 0;

}