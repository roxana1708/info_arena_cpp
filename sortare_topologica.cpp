#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adiacenta[50001];
vector<bool> culoare(50001);
vector<int> ordine;

ifstream f("sortaret.in");
ofstream g("sortaret.out");

void dfs(int nod) {
    culoare[nod] = 1;

    for(auto vecin : adiacenta[nod]) {
        if (culoare[vecin] == 0)
            dfs(vecin);
    }

    culoare[nod] = 2;
    ordine.push_back(nod);
}

int main() {

    int n, m, x, y;
    f >> n >> m;

    for(int i = 0; i < m; i++) {
        f >> x >> y;
        adiacenta[x].push_back(y);
    }

    for(int i = 1; i <= n; i++) {
        if (culoare[i] == 0)
            dfs(i);
    }

    for (int i = ordine.size()-1; i >= 0; i--) {
        g << ordine[i] << " ";
    }
    return 0;
}
