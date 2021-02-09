#include <fstream>

using namespace std;

ifstream f("cautbin.in");
ofstream g("cautbin.out");

int n, m, v[100001], cod, val, i;

int funct1(int st, int dr, int nr) {
    int mijl;

    while(st <= dr) {
        mijl = (st + dr) / 2;

        if(v[mijl] <= nr)
            st = mijl+1;
        else
            dr = mijl-1;
    }

    mijl = (st + dr) / 2;

    if(v[mijl] > nr)
        mijl--;

    if(v[mijl] == nr)
        return mijl;

    return -1;
}

int funct2(int st, int dr, int nr) {
    int mijl;

    while(st <= dr) {
        mijl = (st + dr) / 2;

        if(v[mijl] <= nr)
            st = mijl+1;
        else
            dr = mijl-1;
    }

    mijl = (st + dr) / 2;

    if(v[mijl] > nr)
        mijl--;

    return mijl;
}

int funct3(int st, int dr, int nr) {
    int mijl;

    while(st <= dr) {
        mijl = (st + dr) / 2;

        if(v[mijl] < nr)
            st = mijl+1;
        else
            dr = mijl-1;
    }

    mijl = (st + dr) / 2;

    if(v[mijl] < nr)
        mijl++;

    return mijl;
}

int main() {
    f >> n;

    for(i = 1; i <= n; i++)
        f >> v[i];

    f >> m;

    for(i = 0; i < m; i++) {
        f >> cod >> val;

        switch(cod) {
            case 0:
                g << funct1(1, n, val) << "\n";
                break;
            case 1:
                g << funct2(1, n, val) << "\n";
                break;
            case 2:
                g << funct3(1, n, val) << "\n";
                break;
            default:
                g << "Cod gresit";
        }
    }
    return 0;
}