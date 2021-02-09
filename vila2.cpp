#include <fstream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    ifstream f("vila2.in");
    ofstream g("vila2.out");

    int n, k;
    int sol = 0;



    f >> n >> k;

    int dmax[n], dmin[n];

    int  v[n+1];

    for(int i = 1; i <= n; i++)
        f >> v[i];

    int front_dmin = 1, back_dmin = 0, front_dmax = 1, back_dmax = 0;

    for(int i = 1; i <= n; i++) {

        while(front_dmax <= back_dmax && v[i] >= v[dmax[back_dmax]])
            back_dmax--;


        dmax[++back_dmax] = i;

        if(dmax[front_dmax] < i-k)
            front_dmax++;


        while(front_dmin <= back_dmin && v[i] <= v[dmin[back_dmin]])
            back_dmin--;


        dmin[++back_dmin] = i;


        if(dmin[front_dmin] < i-k)
            front_dmin++;


        if(i >= k)
            sol = max(v[dmax[front_dmax]] - v[dmin[front_dmin]], sol);

    }

    g << sol;
    return 0;
}