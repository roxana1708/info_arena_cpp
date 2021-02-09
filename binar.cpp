#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

struct col{
    int indice;
    char str[2001];
} coloane[2001];

int n, m, i, j;
char linie[2001][2001];

bool cmp(const col &col1, const col &col2) {
    int t = strcmp(col1.str, col2.str);
    if(t == 0)
        return col1.indice < col2.indice;
    else
        return t < 0;
}

int main() {
    ifstream f("binar.in");
    ofstream g("binar.out");

    ios_base::sync_with_stdio(false);

    f >> n >> m;

    for(i = 0; i < n; i++)
        f >> linie[i];

    for(j = 0; j < m; j++) {
        coloane[j].indice = j+1;
        for(i = 0; i < n; i++) {
            coloane[j].str[i] = linie[i][j];
        }
    }

    sort(coloane, coloane+m, cmp);

    for(i = 0; i < m; i++) {
        g << coloane[i].indice << " ";
    }

    return 0;
}